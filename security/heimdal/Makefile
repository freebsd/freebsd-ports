# Ports collection Makefile for:	heimdal
# Version required:			0.2d
# Date created:				10/23/1999
# Whom:					nectar@FreeBSD.ORG
#
# $FreeBSD$
#

DISTNAME=		heimdal-0.2d
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.pdc.kth.se/pub/heimdal/src/ \
			ftp://ftp.replay.com/pub/replay/crypto/APPS/kerberos/heimdal/ \
			ftp://ftp.tuniv.szczecin.pl/dsk4/ftp.replay.com/pub/crypto/APPS/kerberos/heimdal/ \
			ftp://ftp.hacktic.nl/pub/replay/crypto/APPS/kerberos/heimdal/

MAINTAINER=		nectar@FreeBSD.ORG

RESTRICTED=             "Crypto; export-controlled"

MAN1=			kdestroy.1 kgetcred.1 kinit.1 klist.1 kpasswd.1
MAN3=			editline.3 krb5_425_conv_principal.3 \
			krb5_build_principal.3 krb5_free_principal.3 \
			krb5_openlog.3 krb5_parse_name.3 \
			krb5_sname_to_principal.3 krb5_unparse_name.3 \
			krb5_warn.3
MAN5=			krb5.conf.5
MAN8=			hprop.8 hpropd.8 kdc.8 kpasswdd.8 kstash.8 ktutil.8 \
			push.8

USE_LIBTOOL=		YES
USE_GMAKE=		YES
CONFIGURE_ARGS=		--prefix=${PREFIX} --enable-shared

.if !defined(KRB5_KRB4_COMPAT) || ${KRB5_KRB4_COMPAT} == "NO"
CONFIGURE_ARGS+=	--without-krb4
.endif

post-install:
	${SETENV} OBJFORMAT="${PORTOBJFORMAT}" ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
