# New ports collection makefile for:	FreeWAIS-sf
# Version required:	2.2.13
# Date created:		19 November 1996
# Whom:			Pedro Giffuni
#
# $FreeBSD$
#

DISTNAME=	freeWAIS-sf-2.2.13
PKGNAME=	freewais-sf-2.2.13
CATEGORIES=	net databases
MASTER_SITES=	ftp://ls6-ftp.cs.uni-dortmund.de/pub/src/freeWAIS-sf/

MAINTAINER=	ports@FreeBSD.org

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	< ${WRKDIR}/configure.ans
INSTALL_TARGET=	install install.man

MAN1=	catalog.1 dictionary.1 inverted_file.1 makedb.1 mkfmt.1 waisindex.1 \
	waisq.1 waissearch.1 waisserver.1 xwais.1 xwaisq.1
MAN3=	ftw.3 regexp.3 scandir.3

pre-configure:
	@${SED} -e "s:%%CC%%:${CC}:g" \
	        -e "s:%%CFLAGS%%:${CFLAGS}:g" \
		${FILESDIR}/configure.ans.skel > ${WRKDIR}/configure.ans

post-configure:
	@find ${WRKSRC} -type f | \
		xargs ${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g"

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/SF
	${INSTALL_DATA} ${WRKSRC}/doc/SF/fwsf.ps ${PREFIX}/share/doc/SF
.endif

.include <bsd.port.mk>
