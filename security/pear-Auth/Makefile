# Ports collection makefile for:  pear-Auth
# Date created:			  2 February 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Auth
PORTVERSION=	1.2.2
CATEGORIES=	security www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR authentication methods

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

MANIFEST=	Auth.php Container Container.php
TESTDIR=	${PEARDIR}/tests/${PORTNAME}

do-install:
	@${MKDIR} ${PEARDIR}/Auth
.for FILE in ${MANIFEST}
	@${CP} -Rp ${WRKSRC}/${FILE} ${PEARDIR}/Auth
.endfor
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/Auth
	@${CHMOD} -R a-x ${PEARDIR}/Auth/Container/*.php
.if !defined(NOPORTDOCS)
	@${MKDIR} ${TESTDIR}
	@${CP} -Rp ${WRKSRC}/tests/* ${TESTDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${TESTDIR}
	@${ECHO_MSG} "===> Examples installed in ${TESTDIR}."
	@${ECHO_MSG} "     (These tests require PHPUnit - see"
	@${ECHO_MSG} "     <http://pear.php.net/package-info.php?package=PHPUnit>;)."
.endif

.include <bsd.port.post.mk>
