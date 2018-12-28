# Created by: jhuldtgren
# $FreeBSD$

PORTNAME=	blogsum
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.dixongroup.net/

MAINTAINER=	ports@FreeBSD.com
COMMENT=	Simple weblog

RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-XML-RSS>=0:textproc/p5-XML-RSS \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-HTML-Template>=0:www/p5-HTML-Template \
		p5-HTTP-Lite>=0:www/p5-HTTP-Lite \
		${APACHE_PKGNAMEPREFIX}mod_perl2>=0:www/mod_perl2

USES=		apache:run,2.2+ perl5
NO_BUILD=	yes
USE_PERL5=	run

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
	@${MKDIR} ${STAGEDIR}${WWWDIR}/
	@ cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

.include <bsd.port.post.mk>
