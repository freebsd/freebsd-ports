# Ports collection Makefile for:	heimdal
# Date created:				10/23/1999
# Whom:					nectar@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=		heimdal
PORTVERSION=		0.2t
CATEGORIES=		security ipv6
MASTER_SITES=		ftp://ftp.pdc.kth.se/pub/heimdal/src/ \
			ftp://ftp.replay.com/pub/replay/crypto/APPS/kerberos/heimdal/ \
			ftp://ftp.tuniv.szczecin.pl/dsk4/ftp.replay.com/pub/crypto/APPS/kerberos/heimdal/ \
			ftp://ftp.hacktic.nl/pub/replay/crypto/APPS/kerberos/heimdal/

MAINTAINER=		nectar@FreeBSD.ORG

RESTRICTED=		"Crypto; export-controlled"

MAN1=			ftp.1 kdestroy.1 kgetcred.1 kinit.1 klist.1 kpasswd.1 \
			telnet.1 kx.1 rxtelnet.1 rxterm.1 tenletxr.1 pfrom.1
MAN3=			editline.3 krb5_425_conv_principal.3 kafs.3 \
			krb5_build_principal.3 krb5_free_principal.3 \
			krb5_openlog.3 krb5_parse_name.3 \
			krb5_sname_to_principal.3 krb5_unparse_name.3 \
			krb5_warn.3
MAN5=			ftpusers.5 krb5.conf.5
MAN8=			ftpd.8 hprop.8 hpropd.8 kdc.8 kpasswdd.8 kstash.8 \
			ktutil.8 push.8 telnetd.8 kxd.8 verify_krb5_conf.8 \
			string2key.8

USE_LIBTOOL=		yes
INSTALLS_SHLIB=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX} --enable-shared

.if defined(HEIMDAL_HOME)
PREFIX=			${HEIMDAL_HOME}
.endif

.if exists(${X11BASE}/lib/libX11.a) && !defined(WITHOUT_X11)
USE_XLIB=		yes
.endif

.if defined(USE_XLIB)
# These man pages are always installed, so I moved them up
#MAN1+=			kx.1 rxtelnet.1 rxterm.1 tenletxr.1
#MAN8+=			kxd.8
CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--without-x
.endif

.if exists(/usr/lib/libkrb.a) && !defined(WITHOUT_KRB4)
CONFIGURE_ARGS+=	--with-krb4
.elif !defined(KRB5_KRB4_COMPAT)
CONFIGURE_ARGS+=	--without-krb4
.endif

PLIST:=			${WRKDIR}/PLIST

pre-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST}
.if exists(/usr/lib/libkrb.a) && !defined(WITHOUT_KRB4)
	@${CAT} ${PKGDIR}/PLIST.KRB4 >> ${PLIST}
.endif
.if defined(USE_XLIB)
	@${CAT} ${PKGDIR}/PLIST.X11 >> ${PLIST}
.endif

# awful hack to avoid running automake after patching configure
pre-configure:
	@find ${WRKSRC} -name Makefile.in -exec ${TOUCH} {} \;
	@${TOUCH} ${WRKSRC}/include/stamp-h.in
	@${TOUCH} ${WRKSRC}/include/config.h.in

post-install:
	install-info ${PREFIX}/info/heimdal.info ${PREFIX}/info/dir

.include <bsd.port.mk>
