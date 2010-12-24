# ex:ts=8
# New ports collection Makefile for:	pam_mount
# Date created:				14 October 2010
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	pam_mount
PORTVERSION=	2.8
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME:S/_/-/}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A PAM that can mount volumes for a user session

LIB_DEPENDS=	HX.25:${PORTSDIR}/lang/libhx

USE_GNOME=	pkgconfig libxml2
USE_PERL5=	yes
USE_XZ=		yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	libcrypto_LIBS="-L/usr/lib -lcrypto" \
		libcrypto_CFLAGS="-I/usr/include"
CONFIGURE_ARGS+=--localstatedir=/var --with-ssbindir=${PREFIX}/sbin

post-patch:
	${REINPLACE_CMD} -e '11172s|yes|no|' ${WRKSRC}/${CONFIGURE_SCRIPT}
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/src/pam_mount.c
	${REINPLACE_CMD} -e '/dist_security_DATA/s|\.xml$$|.xml.sample|' \
	   ${WRKSRC}/config/Makefile.am ${WRKSRC}/config/Makefile.in
	${MV} ${WRKSRC}/config/pam_mount.conf.xml ${WRKSRC}/config/pam_mount.conf.xml.sample

MAN5=	pam_mount.conf.5
MAN8=	mount.crypt.8 mount.crypt_LUKS.8 mount.crypto_LUKS.8 \
	pmvarrun.8 pmt-ehd.8 umount.crypt.8 umount.crypt_LUKS.8 \
	umount.crypto_LUKS.8 pam_mount.8

.include <bsd.port.mk>
