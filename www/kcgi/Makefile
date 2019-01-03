# $FreeBSD$

PORTNAME=	kcgi
PORTVERSION=	0.10.10
CATEGORIES=	www devel
MASTER_SITES=	http://kristaps.bsd.lv/kcgi/snapshots/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Minimal sandboxed CGI library in C

LICENSE=	ISCL

USES=		tar:tgz

OPTIONS_DEFINE=	EXAMPLES

HAS_CONFIGURE=	yes
MAKE_ARGS=	DATADIR=${EXAMPLESDIR}

post-patch:
	@${REINPLACE_CMD} -e "s/install -m 0555/${INSTALL_PROGRAM}/" \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
