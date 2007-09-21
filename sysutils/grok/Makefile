# Ports collection makefile for:  grok
# Date created:			  07 March 2006
# Whom:				  Wesley Shields <wxs@atarininja.org>
#
# $FreeBSD$
#

PORTNAME=	grok
PORTVERSION=	20070915
CATEGORIES=	sysutils
MASTER_SITES=	http://www.semicomplete.com/files/grok/ \
		http://www.atarininja.org/~wxs/distfiles/

MAINTAINER=	wxs@atarininja.org
COMMENT=	An expert system for real-time log analysis

RUN_DEPENDS=	${SITE_PERL}/Regexp/Common.pm:${PORTSDIR}/textproc/p5-Regexp-Common \
		${SITE_PERL}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent \
		${SITE_PERL}/${PERL_ARCH}/Unix/Syslog.pm:${PORTSDIR}/sysutils/p5-Unix-Syslog \
		${SITE_PERL}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI

USE_PERL5=	yes
USE_RC_SUBR=	grok.sh
NO_BUILD=	yes

SUB_FILES=	pkg-message
SUB_LIST=	PERL=${PERL}

PORTDOCS=	CHANGELIST
PORTEXAMPLES=	line-to-byte-offset.conf
MAN1=	grok.1

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/grok ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/grok_patfind.pl ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/grok.conf ${PREFIX}/etc/grok.conf.sample
	@${INSTALL_MAN} ${WRKSRC}/grok.1 ${MANPREFIX}/man/man1

post-install:
	@if [ ! -f ${PREFIX}/etc/grok.conf ]; then \
		${CP} -p ${PREFIX}/etc/grok.conf.sample ${PREFIX}/etc/grok.conf ; \
	fi
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${INSTALL} -d ${EXAMPLESDIR}/
	@cd ${WRKSRC}/examples/ && \
		${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
