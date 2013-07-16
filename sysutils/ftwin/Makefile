# $FreeBSD$

PORTNAME=	ftwin
PORTVERSION=	0.8.5
PORTREVISION=	10
CATEGORIES=	sysutils
MASTER_SITES=	http://download.meroware.org/ftwin/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	A useful tool to find duplicate files

LIB_DEPENDS=	puzzle:${PORTSDIR}/graphics/libpuzzle \
		apr-1:${PORTSDIR}/devel/apr1 \
		pcre:${PORTSDIR}/devel/pcre

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf aclocal automake autoheader
AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ARGS+=	--with-puzzle=${LOCALBASE}
PLIST_FILES=	bin/ftwin

MAKE_JOBS_SAFE=	yes

PORTDOCS=	AUTHORS EXAMPLES TODO CHANGES KNOWN_BUGS VERSION LICENSE README

MAN8=		ftwin.8

.include <bsd.port.options.mk>
post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
