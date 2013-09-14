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

RUN_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-XML-RSS>=0:${PORTSDIR}/textproc/p5-XML-RSS \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-HTML-Template>=0:${PORTSDIR}/www/p5-HTML-Template \
		p5-HTTP-Lite>=0:${PORTSDIR}/www/p5-HTTP-Lite \
		${APACHE_PKGNAMEPREFIX}mod_perl2>=0:${PORTSDIR}/www/mod_perl2

USES=		perl5
NO_BUILD=	yes
USE_PERL5=	run
USE_APACHE_RUN=	22+

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
