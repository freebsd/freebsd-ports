# Ports collection makefile for:  pear-HTTP_Session
# Date created:			  13 December 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	HTTP_Session
PORTVERSION=	0.4
CATEGORIES=	www devel pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR Object-oriented interface to the session_* family functions

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/sessiondata.sql ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/HTTP_Session_Example.php ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

do-install:
	@${MKDIR} ${PEARDIR}/Session/Container
	@${CP} -p ${WRKSRC}/Session/Container/DB.php ${PEARDIR}/Session/Container
	@${CP} -p ${WRKSRC}/Session/Container.php ${PEARDIR}/Session
	@${CP} ${WRKSRC}/Session.php ${PEARDIR}
	@${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/Session.php
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/Session

.include <bsd.port.post.mk>
