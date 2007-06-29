# Ports collection Makefile for:	krb4
# Date created:				03/04/2003
# Whom:					nectar@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	krb4
PORTVERSION=	1.2.2
PORTREVISION=	3
CATEGORIES=	security ipv6
MASTER_SITES=	ftp://ftp.pdc.kth.se/pub/krb/src/

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	KTH Kerberos 4

CONFLICTS=	krb5-[0-9]* heimdal-[0-9]* srp-[0-9]*
USE_LDCONFIG=	yes
# Don't remove this.  This port installs several applications
# which have the same name as some in the base system (e.g.
# ftp, telnet, su).
PREFIX?=	${LOCALBASE}/krb4
NO_MTREE=	yes	# Otherwise we end up with dozens of extra directories in ${PREFIX}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=\
	--enable-shared		\
	--disable-otp		\
	--disable-afs-support	\
	--without-x
CONFIGURE_ENV+=	\
	"CFLAGS=${CFLAGS}" \
	"CPPFLAGS=-DOPENSSL_DES_LIBDES_COMPATIBILITY" \
	"LDFLAGS=-Wl,-rpath,${PREFIX}/lib"

INFO=	kth-krb

SUB_FILES+=	pkg-message

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} "or simply \`make setuids'."

setuids:
.for file in rsh rcp rlogin su
	${CHOWN} 0:0 ${PREFIX}/bin/${file}
	${CHMOD} u+s ${PREFIX}/bin/${file}
.endfor

.include "Makefile.man"
.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 700019
BROKEN=		Incorrect pkg-plist on FreeBSD >= 7.0
.endif

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif
.include <bsd.port.post.mk>
