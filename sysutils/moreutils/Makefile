# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTNAME=	moreutils
PORTVERSION=	0.50
CATEGORIES=	sysutils
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Additional Unix utilities

LICENSE=	GPLv2

RUN_DEPENDS=	p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

ALL_TARGET=	bins
USES=		perl5
WRKSRC=		${WRKDIR}/${PORTNAME}

MANPAGES_ALL_TARGET=	mans

CANNED_MANPAGES=errno.1 \
		ifne.1 \
		isutf8.1 \
		lckdo.1 \
		mispipe.1 \
		pee.1 \
		sponge.1
MANPAGES=	chronic.1 \
		combine.1 \
		ts.1 \
		vidir.1 \
		vipe.1 \
		zrun.1 \
		${CANNED_MANPAGES}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|share/xml/docbook/schema/dtd/|local/share/xml/docbook/|' ${WRKSRC}/*.docbook
.if ${PORT_OPTIONS:MMANPAGES}
	@cd ${FILESDIR}/ && ${CP} ${CANNED_MANPAGES} ${WRKSRC}/
.endif

post-install:
.if ${PORT_OPTIONS:MMANPAGES}
	cd ${WRKSRC}/ && ${INSTALL_MAN} ${MANPAGES} ${STAGEDIR}${PREFIX}/man/man1/
.endif

.include <bsd.port.mk>
