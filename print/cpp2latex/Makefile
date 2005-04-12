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
MASTER_SITES=	http://roederberg.dyndns.org/~arnold/file_share/cpp2latex/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert C++ source to a file you can input in an LaTeX-document

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-pedantic||g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in AUTHORS ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
