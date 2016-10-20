# $FreeBSD$

PORTNAME=	kcgi
PORTVERSION=	0.9.1
CATEGORIES=	www devel
MASTER_SITES=	http://kristaps.bsd.lv/kcgi/snapshots/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Minimal sandboxed CGI library in C

LICENSE=	ISCL

USES=		tar:tgz gmake

OPTIONS_DEFINE=	EXAMPLES

BROKEN_FreeBSD_9=	Requires capsicum

HAS_CONFIGURE=	yes
MAKE_ARGS=	DATADIR=${EXAMPLESDIR}
MAKEFILE=	GNUmakefile

post-patch:
	@${REINPLACE_CMD} -e "s/install -m 0555/${INSTALL_PROGRAM}/" \
		${WRKSRC}/GNUmakefile

.include <bsd.port.mk>
