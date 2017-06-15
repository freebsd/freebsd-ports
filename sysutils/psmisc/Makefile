# Created by: rantapaa@uswest.net
# $FreeBSD$

PORTNAME=	psmisc
PORTVERSION=	22.16
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Port of the Linux pstree, killall, and pidof commands

LICENSE=	GPLv2

BUILD_DEPENDS=	gsed:textproc/gsed

CONFLICTS=	pidof-[0-9]* pstree-2.[0-9]*

GNU_CONFIGURE=	yes
USES=		gmake ncurses

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

post-patch:
	@${REINPLACE_CMD} -e '/^#define COMM_LEN / s|16|254|' ${WRKSRC}/src/comm.h

post-install:
	@${LN} -fs killall ${STAGEDIR}${PREFIX}/bin/pidof

.include <bsd.port.mk>
