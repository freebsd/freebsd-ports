# New ports collection makefile for:	chpp
# Date created:				4 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	chpp
PORTVERSION=	0.3.5
CATEGORIES=	textproc
MASTER_SITES=	http://www.complang.tuwien.ac.at/~schani/chpp/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Non-intrusive full-featured text preprocessor

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/share

EXAMPLES_DIR=	${PREFIX}/share/examples/chpp

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile"
.endif

post-install:
	@${MKDIR} ${EXAMPLES_DIR}
	${TAR} -C ${WRKSRC}/test -cf - . | \
		${TAR} -C ${EXAMPLES_DIR} --unlink -xf -
	@${FIND} ${EXAMPLES_DIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${EXAMPLES_DIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS NEWS README
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
