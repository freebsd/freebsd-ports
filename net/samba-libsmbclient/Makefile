# New ports collection makefile for:	samba-libsmbclient
# Date created:				23 Juli 2003
# Whom:					Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTREVISION=		0
PORTEPOCH=		0
PKGNAMESUFFIX=		-libsmbclient

MAINTAINER=		kwm@rainbow-runner.nl
COMMENT=		The shared lib from the samba packages

CONFLICTS=		samba-3.*

USE_ICONV=		yes
GNU_CONFIGURE=		yes
INSTALLS_SHLIB=		yes

SAMBA_PORT=		samba-devel
SAMBA_SUBPORT=		yes

MASTERDIR=		${.CURDIR}/../${SAMBA_PORT}
PKGDIR=			${.CURDIR}
# We WANT libsmbclient support :)
CONFIGURE_ARGS+=	--with-libsmbclient
CONFIGURE_ARGS+=	--with-libiconv
# This is taken from SAMBA_PORT(grep without)
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--without-utmp
CONFIGURE_ARGS+=	--without-winbind
CONFIGURE_ARGS+=	--without-ads
CONFIGURE_ARGS+=	--without-ldap
CONFIGURE_ARGS+=	--without-ldapsam
CONFIGURE_ARGS+=	--without-krb5
CONFIGURE_ARGS+=	--without-pam_smbpass

do-build:
	cd ${WRKSRC} && ${MAKE} include/proto.h
	cd ${WRKSRC} && ${MAKE} libsmbclient

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/libsmbclient.h ${PREFIX}/include
	${INSTALL_SCRIPT} ${WRKSRC}/bin/libsmbclient.a ${PREFIX}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/bin/libsmbclient.so.0 ${PREFIX}/lib
	${LN} -snf libsmbclient.so.0 ${PREFIX}/lib/libsmbclient.so

.include "${MASTERDIR}/Makefile"
