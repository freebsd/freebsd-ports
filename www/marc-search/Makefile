# New ports collection makefile for:	marc-search
# Date created:		25 November 1998
# Whom:			Sheldon Hearn <axl@iafrica.com>
#
# $FreeBSD$
#

PORTNAME=	marc-search
PORTVERSION=	4.3
CATEGORIES=	www
MASTER_SITES=	http://www.oac.uci.edu/indiv/ehood/contrib/marc-search/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	sheldonh@FreeBSD.org

BROKEN=		"requires AppCfg.pm, supplied with Wilma"

RUN_DEPENDS=	mhonarc:${PORTSDIR}/www/mhonarc \
		${PREFIX}/lib/perl5/site_perl/${PERL_VER}/CGI_Lite.pm:${PORTSDIR}/www/p5-CGI_Lite

USE_PERL5=	YES
NO_BUILD=	YES
NO_PACKAGE=	requires site-specific configuration at build time
IS_INTERACTIVE= requires site-specific configuration at build time

# You must tailor these variables to match your sites config
# PUB_HTML=public_html		# subdir name for "~user" usage
# DOCROOT=${PREFIX}/www/data	# web page hierarchy root
# SCRIPTDIR=/cgi-bin		# script directory name
HOSTNAME!= hostname

MARC_LIBS= 	Marc.pm Marc/Form.pm Marc/Search.pm

do-configure:
.if !defined(PUB_HTML) || !defined(DOCROOT) || !defined(SCRIPTDIR)
	@${ECHO_MSG} "You must tailor the port Makefile and set PUB_HTML, DOCROOT,"
	@${ECHO_MSG} "and SCRIPTDIR to match your site configuration."
	@${FALSE}
.else
	${CP} ${FILESDIR}/marc-search.conf ${WRKSRC}/
	for i in marc-search.cgi marc-search.conf ; do \
		${SED} -e 's#XX_PERL_PATH_XX#${PERL}#' \
	    	-e 's#XX_PERL_VER_XX#${PERL_VER}#' \
	    	-e 's#XX_PREFIX_XX#${PREFIX}#' \
	    	-e 's#XX_PUB_HTML_XX#${PUB_HTML}#' \
	    	-e 's#XX_HOSTNAME_XX#${HOSTNAME}#' \
	    	-e 's#XX_DOCROOT_XX#${DOCROOT}#' \
	    	-e 's#XX_SCRIPTDIR_XX#${SCRIPTDIR}#' \
	    	< ${WRKSRC}/$${i} \
	    	> ${WRKSRC}/$${i}.tmp \
	    	&& ${MV} ${WRKSRC}/$${i}.tmp ${WRKSRC}/$${i} ; \
	done
.endif

do-install:
	${MKDIR} ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/Marc \
	    ${PREFIX}/share/doc/marc-search
.for i in ${MARC_LIBS}
	${INSTALL_DATA} ${WRKSRC}/${i} \
		${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${i}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/marc-search.cgi ${PREFIX}/www/cgi-bin
	${INSTALL_DATA} ${WRKSRC}/marc-search.conf ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/docs/marc-search.html ${PREFIX}/www/data
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/marc-search/

.include <bsd.port.mk>
