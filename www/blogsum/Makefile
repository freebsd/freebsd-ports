# New ports collection makefile for:   blogsum
# Date created:        2 November 2009
# Whom:                jhuldtgren
#
# $FreeBSD$
#

PORTNAME=	blogsum
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.dixongroup.net/

MAINTAINER=	jhuldtgren@gmail.com
COMMENT=	Simple weblog

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite \
		${SITE_PERL}/${PERL_ARCH}/mod_perl2.pm:${PORTSDIR}/www/mod_perl2 \
		${SITE_PERL}/XML/RSS.pm:${PORTSDIR}/textproc/p5-XML-RSS \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template \
		${SITE_PERL}/HTTP/Lite.pm:${PORTSDIR}/www/p5-HTTP-Lite

NO_BUILD=	yes
USE_PERL5_RUN=	yes

USE_APACHE_RUN=	20+

.include <bsd.port.pre.mk>

SUB_FILES=	pkg-message
SUB_LIST+=	APACHEETCDIR=${APACHEETCDIR} APACHEMODDIR=${APACHEMODDIR} WWWOWN=${WWWOWN}

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may set following options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WWWDIR=${WWWDIR}	Where do you put httpd's document root?"
	@${ECHO_MSG} ""

do-install:
	@${MKDIR} ${WWWDIR}/
	@ cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}/

post-install:
	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
