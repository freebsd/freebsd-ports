# Created by: Pedro Giffuni <pgiffuni@fps.biblos.unal.edu.co>
# $FreeBSD$

PORTNAME=	freewais-sf
PORTVERSION=	2.2.14
PORTREVISION=	1
CATEGORIES=	net databases
MASTER_SITES=	ftp://ftp.ntua.gr/pub/net/freewais/ \
		http://ftp.ntua.gr/pub/net/freewais/
DISTNAME=	freeWAIS-sf-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhanced Wide Area Information Server

DEPRECATED=	Unmaintained since 1999
EXPIRATION_DATE=	2014-04-10
USES=		perl5
HAS_CONFIGURE=	yes
USE_PERL5=	build
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ENV=	PREFIX="${PREFIX}"
CONFIGURE_ARGS=	-sde -Dprefix="${PREFIX}" \
		-Darchname="${MACHINE_ARCH}-freebsd"
INSTALL_TARGET=	install install.man

CFLAGS+=	-Wno-return-type	# to pacify Clang

PORTDOCS=	fwsf.ps
MAN1=		catalog.1 dictionary.1 inverted_file.1 mkfmt.1 waisindex.1 \
		waisq.1 waissearch.1 waisserver.1 xwais.1 xwaisq.1
MAN3=		ftw.3 regexp.3 scandir.3

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not install on powerpc: drops core
.endif

post-extract:
	${CP} ${FILESDIR}/freebsd.sh ${WRKSRC}/hints

# Try to fix parallel builds (-jX)
post-patch:
	@${REINPLACE_CMD} -e '/$$(RM) $$@/,+1d' \
		${WRKSRC}/lib/ctype/Makefile.SH

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/SF/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
