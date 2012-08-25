# New ports collection makefile for: ifdepd
# Date created:         03 05 2012
# Whom:                 Alexander Hausner <alex@hugo.bmg.gv.at>
# $FreeBSD$

PORTNAME=	mod_authn_otp
PORTVERSION=	1.1.4
CATEGORIES=	www
MASTER_SITES=	http://mod-authn-otp.googlecode.com/files/ \
		http://alex.bmg.gv.at/programs/
DIST_SUBDIR=	apache2

MAINTAINER=	alex@hugo.bmg.gv.at
COMMENT=	Apache module for one-time password authentication

MAKE_JOBS_SAFE=	yes

HAS_CONFIGURE=	yes
USE_APACHE=	22+

PORTEXAMPLES=	users.sample

.include <bsd.port.options.mk>

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/users.sample ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
