# Created by: kaz@kobe1995.net (NAKAMURA Kauzushi)
# $FreeBSD$

PORTNAME?=	mbmon
PORTVERSION=	205
PORTREVISION?=	6
CATEGORIES=	sysutils
MASTER_SITES=	http://www.nt.phys.kyushu-u.ac.jp/shimizu/download/xmbmon/
DISTNAME=	xmbmon${PORTVERSION}

MAINTAINER=	5u623l20@gmail.com
COMMENT?=	Motherboard monitor for LM78/79, W8378x, AS99127F, VT82C686 and ADM9240

DEPRECATED=	Use sysutils/xmbmon instead. This port will be removed soon
EXPIRATION_DATE=2014-01-31

PORTSCOUT=	limit:^[0-9]+$
PATCH_SITES+=	${MASTER_SITES}
PATCHFILES+=	xmbmon${PORTVERSION}_fflush.patch

ONLY_FOR_ARCHS=	i386 amd64
GNU_CONFIGURE=	yes

MAKE_ARGS=	PROGRAM="${PORTNAME}"

PLIST_FILES+=	bin/${PORTNAME}
MAN1?=		mbmon.1
PORTDOCS=	ChangeLog ChangeLog.jp ReadMe ReadMe.jp ReadMe.tech

OPTIONS_DEFINE=	ASUS SMB
OPTIONS_DEFAULT=SMB
ASUS_DESC=	"Enable A7N8X-VM support"
SMB_DESC=	"Enable smb(4) support"

.if ${PORTNAME} == "mbmon"
USE_RC_SUBR=	mbmon
.endif

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASUS}
PATCHFILES+=	xmbmon${PORTVERSION}_A7N8X-VM.patch
.endif

post-patch:
	@${REINPLACE_CMD} -e 's+/usr/share/doc/mbmon+${DOCSDIR}+' ${WRKSRC}/mbmon.1
.if ${PORT_OPTIONS:MSMB}
	@${REINPLACE_CMD} -e 's/^DEFS=/&-DSMBUS_IOCTL /' ${WRKSRC}/Makefile.in
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${CHMOD} u+s ${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${MAN1:S|^|${WRKSRC}/|} ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
