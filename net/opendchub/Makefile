# New ports collection makefile for:	opendchub
# Date created:			May 29, 2002
# Whom:				Munish Chopra <mchopra@engmail.uwaterloo.ca>
#
# $FreeBSD$
#

PORTNAME=	opendchub
PORTVERSION=	0.7.14
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unofficial Unix version of the Direct Connect Hub software

USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/* ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		"needs at least perl 5.6.1 to build"
.endif

.include <bsd.port.post.mk>
