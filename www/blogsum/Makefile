# New ports collection makefile for:   blogsum
# Date created:        2 November 2009
# Whom:                jhuldtgren
#
# $FreeBSD$
#

PORTNAME=	blogsum
PORTVERSION=	1.1
CATEGORIES=	www
MASTER_SITES=	http://www.dixongroup.net/

MAINTAINER=	jhuldtgren@gmail.com
COMMENT=	Simple weblog

PERL_MODULES=	${APXS}:${PORTSDIR}/${APACHE_PORT} \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite \
		${SITE_PERL}/XML/RSS.pm:${PORTSDIR}/textproc/p5-XML-RSS \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template \
		${SITE_PERL}/HTTP/Lite.pm:${PORTSDIR}/www/p5-HTTP-Lite

NO_BUILD=	yes
USE_PERL5_RUN=	yes

.if defined(WITH_APACHE2)
USE_APACHE=	2.0+
.else
USE_APACHE=	1.3+
.endif

.if defined(WITH_APACHE2)
PERL_MODULES+=	${LOCALBASE}/${APACHEMODDIR}/mod_perl.so:${PORTSDIR}/www/mod_perl2
DEPENDS_ARGS+=	WITHOUT_MODPERL=yes
DEPENDS_ARGS+=	WITH_MODPERL2=yes
.else
# XXX - probe for static mod_perl using `httpd -l | grep perl`
PERL_MODULES+=	${LOCALBASE}/libexec/apache/libperl.so:${PORTSDIR}/www/mod_perl \
		${SITE_PERL}/${PERL_ARCH}/Apache/Request.pm:${PORTSDIR}/www/p5-libapreq
.endif

RUN_DEPENDS+=	${PERL_MODULES}

SUB_FILES=	pkg-message
SUB_LIST+=	APACHEETCDIR=${APACHEETCDIR} APACHEMODDIR=${APACHEMODDIR} WWWOWN=${WWWOWN}

.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may set following options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITH_APACHE2=yes			Use apache2+ instead of apache 1.3"
	@${ECHO_MSG} "WWWDIR=${WWWDIR}	Where do you put httpd's document root?"
	@${ECHO_MSG} ""

do-install:
	@${MKDIR} ${WWWDIR}
	@ cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}

post-install:
	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
