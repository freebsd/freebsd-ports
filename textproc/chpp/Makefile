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

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/share

EXAMPLES_DIR=	${PREFIX}/share/examples/chpp
DOCS_DIR=	${PREFIX}/share/doc/chpp

post-install:
	@${MKDIR} ${EXAMPLES_DIR}
	${TAR} -C ${WRKSRC}/test -cf - . | \
		${TAR} -C ${EXAMPLES_DIR} --unlink -xf -
	@find ${EXAMPLES_DIR} | xargs ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@find ${EXAMPLES_DIR} -type f | xargs ${CHMOD} ${SHAREMODE}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCS_DIR}
.for file in AUTHORS NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCS_DIR}
.endfor
.endif

.include <bsd.port.mk>
