# ex:ts=8
# New ports collection makefile for:	cpp2latex
# Date created:			Jul 20, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cpp2latex
PORTVERSION=	2.3
CATEGORIES=	print
MASTER_SITES=	http://www.arnoldarts.de/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert C++ source to a file you can input in an LaTeX-document

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
