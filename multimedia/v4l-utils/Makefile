# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	v4l-utils
PORTREVISION=	0

COMMENT=	Video4Linux utilities

MASTERDIR=	${.CURDIR}/../libv4l
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

INSTALL_WRKSRC=	${WRKSRC}/utils

# no need for udev rules
post-install:
	@${RM} -r ${STAGEDIR}/lib/udev

.include "${MASTERDIR}/Makefile"
