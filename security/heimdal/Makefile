# Ports collection Makefile for:	heimdal
# Date created:						10/23/1999
# Whom:								nectar@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=		heimdal
PORTVERSION=	0.3d
PORTREVISION=	2
CATEGORIES=		security ipv6
MASTER_SITES=	ftp://ftp.pdc.kth.se/pub/heimdal/src/ \
				ftp://ftp.replay.com/pub/replay/crypto/APPS/kerberos/heimdal/ \
				ftp://ftp.tuniv.szczecin.pl/dsk4/ftp.replay.com/pub/crypto/APPS/kerberos/heimdal/ \
				ftp://ftp.hacktic.nl/pub/replay/crypto/APPS/kerberos/heimdal/

MAINTAINER=		nectar@FreeBSD.ORG

.if defined(WITH_LDAP)
LIB_DEPENDS=	ldap.2:${PORTSDIR}/net/openldap2
.endif

RESTRICTED=		"Crypto; export-controlled"

MAN1=			ftp.1 kdestroy.1 kf.1 kgetcred.1 kinit.1 klist.1 kpasswd.1 \
				krb5-config.1 kx.1 otp.1 otpprint.1 pfrom.1 rxtelnet.1 \
				rxterm.1 telnet.1 tenletxr.1 xnlock.1
MAN3=			editline.3 kafs.3 krb5_425_conv_principal.3 krb5_appdefault.3 \
				krb5_build_principal.3 krb5_config.3 krb5_free_principal.3 \
				krb5_openlog.3 krb5_parse_name.3 krb5_sname_to_principal.3 \
				krb5_unparse_name.3 krb5_warn.3
MAN5=			ftpusers.5 krb5.conf.5
MAN8=			ftpd.8 hprop.8 hpropd.8 kadmin.8 kadmind.8 kdc.8 kerberos.8 \
				kfd.8 kpasswdd.8 kstash.8 ktutil.8 kxd.8 push.8 string2key.8 \
				telnetd.8 verify_krb5_conf.8

# must use supplied ltconfig et. al. for now
#USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}--freebsd${OSREL}
INSTALLS_SHLIB=		yes
CONFIGURE_ENV=		CPPFLAGS="${OPENSSL_INCLUDE}"
CONFIGURE_ARGS=		--prefix=${PREFIX} --enable-shared
.if defined(WITH_LDAP)
CONFIGURE_ARGS+=	--with-openldap=${LOCALBASE}
.endif

.if defined(HEIMDAL_HOME)
PREFIX=				${HEIMDAL_HOME}
.endif

.if exists(${X11BASE}/lib/libX11.a) && !defined(WITHOUT_X11)
USE_XLIB=			yes
.endif

.if defined(USE_XLIB)
CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--without-x
.endif

.if exists(/usr/lib/libkrb.a) && !defined(WITHOUT_KRB4)
CONFIGURE_ARGS+=	--with-krb4
.elif !defined(KRB5_KRB4_COMPAT)
CONFIGURE_ARGS+=	--without-krb4
.endif

# OpenSSL 0.9.6 and later have MD4 and can be used in the build
.if exists(/usr/include/openssl/md4.h) && exists(/usr/lib/libdes.a)
OPENSSL_INCLUDE=	-I/usr/include/openssl
OPENSSL_IN_BASE=	YES
.endif

PLIST:=				${WRKDIR}/PLIST

# The crypto APIs in the included libdes are trivially different from
# those in OpenSSL, e.g. MD5Init versus MD5_Init.  To make things simpler,
# we normalize the API to use the latter naming convention.  These are a
# list of the files that must be munged.
CRYPTO_FIXUP=		lib/des/fcrypt.c lib/des/md4.c lib/des/md4.h \
					lib/des/md5.c lib/des/md5.h lib/des/mdtest.c \
					lib/des/sha.c lib/des/sha.h lib/gssapi/8003.c \
					lib/gssapi/get_mic.c lib/gssapi/unwrap.c \
					lib/gssapi/verify_mic.c lib/gssapi/wrap.c \
					lib/krb5/crypto.c lib/krb5/replay.c lib/otp/otp_md.c

pre-configure:
	@(set -e; \
	cd ${CONFIGURE_WRKSRC}; \
	find . -type f -name 'Makefile.in' -print | xargs perl -i -pe \
	's,\$$\(top_builddir\)/lib/com_err/compile_et,compile_et,';)
	(cd ${WRKSRC} && ${PERL} -i.orig -p \
		-e 's/(SHA1|MD5|MD4)(Init|Update|Final)/$$1_$$2/g;' \
		-e 's/SHA1_CTX/SHA_CTX/g;' \
		-e 's/des_set_odd_parity/des_fixup_key_parity/g;' \
		${CRYPTO_FIXUP})

pre-install:
	@${CP} ${PKGDIR}/pkg-plist ${PLIST}
.if exists(/usr/lib/libkrb.a) && !defined(WITHOUT_KRB4)
	@${CAT} ${PKGDIR}/pkg-plist.krb4 >> ${PLIST}
.endif
.if defined(USE_XLIB)
	@${CAT} ${PKGDIR}/pkg-plist.x11 >> ${PLIST}
.endif
.if !defined(OPENSSL_IN_BASE)
	@${CAT} ${PKGDIR}/pkg-plist.des >> ${PLIST}
.endif

# awful hack to avoid running automake after patching configure
pre-configure:
	@find ${WRKSRC} -name Makefile.in -exec ${TOUCH} {} \;
	@${TOUCH} ${WRKSRC}/include/stamp-h.in
	@${TOUCH} ${WRKSRC}/include/config.h.in

post-install:
	install-info ${PREFIX}/info/heimdal.info ${PREFIX}/info/dir

.include <bsd.port.mk>
