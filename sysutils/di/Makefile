# New ports collection makefile for:	di
# Date created:			31 August 2002
# Whom:				Brad Lanam <bll@gentoo.com>
#
# $FreeBSD$
#

PORTNAME=	di
PORTVERSION=	3.10
CATEGORIES=	sysutils
MASTER_SITES=	http://www.gentoo.com/di/

MAINTAINER=	bll@gentoo.com
COMMENT=	Disk Information Utility

USE_GETTEXT=	yes

MAN1=		di.1

do-configure:
	(cd ${WRKSRC}; \
		CC="$(CC)" CFLAGS="$(CFLAGS)" \
		LDFLAGS="$(LDFLAGS)" prefix="$(PREFIX)" \
		LOCALEDIR="$(PREFIX)/share/locale" \
		./Build config.h)

do-build:
	(cd ${WRKSRC}; \
		CC="$(CC)" CFLAGS="$(CFLAGS)" \
		LDFLAGS="$(LDFLAGS)" prefix="$(PREFIX)" \
		LOCALEDIR="$(PREFIX)/share/locale" \
		./Build)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/di ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mi ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/di.1 ${PREFIX}/man/man1
	(cd ${WRKSRC}; \
		CC="$(CC)" CFLAGS="$(CFLAGS)" \
		LDFLAGS="$(LDFLAGS)" prefix="$(PREFIX)" \
		LOCALEDIR="$(PREFIX)/share/locale" \
		./Build build-po)
	-(cd ${WRKSRC}/po;for i in *.po; do \
	j=`echo $$i | $(SED) 's,\\.po$$,,'`; \
	test -d ${PREFIX}/share/locale/$$j || \
		mkdir ${PREFIX}/share/locale/$$j; \
	test -d ${PREFIX}/share/locale/$$j/LC_MESSAGES || \
		mkdir ${PREFIX}/share/locale/$$j/LC_MESSAGES; \
	${INSTALL_DATA} $$j.mo \
	${PREFIX}/share/locale/$$j/LC_MESSAGES/di.mo; \
        $(RM) -f $$j.mo; \
	done)

.include <bsd.port.mk>
