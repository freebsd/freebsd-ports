# Created by: Ilya A. Arkhipov <rum1cro@yandex.ru>
# $FreeBSD$

PORTNAME=	dialog4ports
PORTVERSION=	0.1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://m1cro.tk/dialog4ports/ \
		ftp://invisible-island.net/dialog/:dialog

MAINTAINER=	rum1cro@yandex.ru
COMMENT=	Console Interface to configure ports

# CCACHE has options, so may need d4p, make d4p not ccache friendly
# to avoid circular dependency
NO_CCACHE=	yes
USE_XZ=		yes
MANCOMPRESSED=	yes
MAN1=		${PORTNAME}.1
MAKE_ENV+=	__MAKE_CONF=/dev/null SRCCONF=/dev/null

PLIST_FILES=	bin/dialog4ports

MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900030
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${DIALOGNAME}.tgz:dialog
DIALOGNAME=	dialog-1.1-20120706
EXTRACT_CMD=	${CAT}
EXTRACT_BEFORE_ARGS=

MAKE_ENV+=	DIALOGSOURCES=${WRKDIR}/${DIALOGNAME}

do-configure:
	@cd ${WRKDIR}/${DIALOGNAME}; ./configure

.endif

.include <bsd.port.post.mk>
