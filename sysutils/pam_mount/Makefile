# Created by: gahr
# $FreeBSD$

PORTNAME=	pam_mount
PORTVERSION=	2.12
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME:S/_/-/}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	PAM module that can mount volumes for a user session

LICENSE=	LGPL21 GPLv2
LICENSE_COMB=	multi

LIB_DEPENDS=	libHX.so:${PORTSDIR}/lang/libhx

USES=		pkgconfig perl5
USE_GNOME=	libxml2
USE_XZ=		yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	libcrypto_LIBS="-L/usr/lib -lcrypto" \
		libcrypto_CFLAGS="-I/usr/include"
CONFIGURE_ARGS+=--localstatedir=/var \
		--without-cryptsetup \
		--with-ssbindir=${PREFIX}/sbin

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/src/pam_mount.c
	${REINPLACE_CMD} -e '/dist_security_DATA/s|\.xml$$|.xml.sample|' \
	   ${WRKSRC}/config/Makefile.am ${WRKSRC}/config/Makefile.in
	${MV} ${WRKSRC}/config/pam_mount.conf.xml ${WRKSRC}/config/pam_mount.conf.xml.sample
	${FIND} ${WRKSRC} -name "*.c" -exec ${REINPLACE_CMD} -e 's|HXformat2_aprintf|HXformat_aprintf|g' {} \;

.include <bsd.port.mk>
