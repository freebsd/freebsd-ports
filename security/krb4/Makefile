# Ports collection Makefile for:	krb4
# Date created:				03/04/2003
# Whom:					nectar@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	krb4
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	security ipv6
MASTER_SITES=	ftp://ftp.pdc.kth.se/pub/krb/src/

MAINTAINER=	nectar@FreeBSD.ORG
COMMENT=	KTH Kerberos 4

# Don't remove this.  This port installs several applications
# which have the same name as some in the base system (e.g.
# ftp, telnet, su).
PREFIX?=	${LOCALBASE}/krb4
NO_MTREE=	yes	# Otherwise we end up with dozens of extra directories in ${PREFIX}

PKGMESSAGE=	${WRKDIR}/pkg-message
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= \
	--enable-shared		\
	--disable-otp		\
	--disable-afs-support	\
	--without-x
CONFIGURE_ENV+=	\
	"CFLAGS=${CFLAGS}" \
	"CPPFLAGS=-DOPENSSL_DES_LIBDES_COMPATIBILITY" \
	"LDFLAGS=-Wl,-rpath,${PREFIX}/lib"

INFO=	kth-krb

post-install:
	install-info ${PREFIX}/info/kth-krb.info ${PREFIX}/info/dir
	${SED} -e "s~%%PREFIX%%~${PREFIX}~g" \
	    < ${.CURDIR}/pkg-message > ${PKGMESSAGE}
	@${ECHO_CMD} "*** ATTENTION ***"
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} "or simply \`make setuids'."

setuids:
.for file in rsh rcp rlogin su
	${CHOWN} 0:0 ${PREFIX}/bin/${file}
	${CHMOD} u+s ${PREFIX}/bin/${file}
.endfor

.include "Makefile.man"
.include <bsd.port.pre.mk>
.if ${ARCH} == "amd64"
CFLAGS+= -fPIC
.endif
.include <bsd.port.post.mk>
