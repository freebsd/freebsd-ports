# New ports collection makefile for:	DirComp
# Date created:		20 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DirComp
PORTVERSION=	1.3.10
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/${PORTNAME:S/C/c/}-${PORTVERSION}/

MAINTAINER=	corky1951@comcast.net
COMMENT=	Compare two directories

.ifndef WITHOUT_X11
LIB_DEPENDS=	XGP.0:${PORTSDIR}/devel/libXGP
PLIST_FILES+=	bin/XDirComp
.else
MK_PATCH+=	s/@MYSUBDIRS@/Common/g;
.endif
LIB_DEPENDS+=	YGP.0:${PORTSDIR}/devel/libYGP

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE} --disable-rpath
PLIST_FILES+=	bin/DirComp \
		share/locale/de/LC_MESSAGES/DirComp.mo \
		share/locale/en/LC_MESSAGES/DirComp.mo \
		share/locale/es/LC_MESSAGES/DirComp.mo

post-patch:
	@${REINPLACE_CMD} -Ee 's/^(SUBDIRS.*)doc/\1/;${MK_PATCH}' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
