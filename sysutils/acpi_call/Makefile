# Created by: Maxim Ignatenko <gelraen.ua@gmail.com>
# $FreeBSD$

PORTNAME=	acpi_call
PORTVERSION=	1.0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://projects.ukrweb.net/files/ \
		http://imax.in.ua/files/

MAINTAINER=	gelraen.ua@gmail.com
COMMENT=	Kernel module for calling ACPI methods from userspace

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	aarch64 amd64 i386
ONLY_FOR_ARCHS_REASON=	not relevant for most non-x86-derived architectures

USES=		kmod

post-patch:
	@${REINPLACE_CMD} -e 's,/sys,$${SYSDIR},' ${WRKSRC}/Makefile

post-build:
	@${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC} util

do-install:
	${INSTALL_KLD} ${WRKSRC}/${PORTNAME}.ko ${STAGEDIR}${KMODDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
