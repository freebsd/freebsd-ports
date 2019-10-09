# Created by: jim@thehousleys.net
# $FreeBSD$

PORTNAME=	healthd
PORTVERSION=	0.7.9
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://healthd.thehousleys.net/ \
		LOCAL/ohauer

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Daemon to monitor vital motherboard parameters

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

ONLY_FOR_ARCHS=	i386 amd64

USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--exec-prefix=${PREFIX}
INSTALL_TARGET=	install-all
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	IPV6 FULL_CONFIG DOCS

FULL_CONFIG_DESC=		Remotely reading the full config

IPV6_CONFIGURE_ENABLE=		ipv6
FULL_CONFIG_CONFIGURE_ENABLE=	full-config

post-patch:
	@${REINPLACE_CMD} -e 's| @exec_prefix@| $$(DESTDIR)@exec_prefix@|' \
		${WRKSRC}/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/PROTOCOL ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
