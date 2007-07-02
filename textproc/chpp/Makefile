# New ports collection makefile for:	chpp
# Date created:				4 May 1999
# Whom:					Andrey Zakhvatov <andy@FreeBSD.org>
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

INFO=		chpp

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		Does not compile
.endif

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${TAR} -C ${WRKSRC}/test -cf - . | \
		${TAR} -C ${EXAMPLESDIR} --unlink -xf -
.if !defined(NOPORTEXAMPLES)
	@${FIND} ${EXAMPLESDIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${EXAMPLESDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS NEWS README
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
