# New ports collection makefile for:	LPRng
# Date created:		2 Apr 1997
# Whom:			desmo@bandwidth.org
#
# $FreeBSD$
#

PORTNAME=	LPRng
PORTVERSION=	3.6.26
CATEGORIES=	sysutils print
MASTER_SITES=	ftp://ftp.astart.com/pub/LPRng/LPRng/
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	desmo@bandwidth.org

PLIST_SUB+=	LPRNG_VER=${PORTVERSION}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAKEFILE=	Makefile.bsd
HAS_CONFIGURE=	yes
CONFIGURE_ARGS= \
		--with-sbindir=${PREFIX}/sbin \
		--with-filterdir=${PREFIX}/libexec/filters \
		--with-lpd_conf_path=/etc/lpd.conf \
		--with-lpd_perms_path=/etc/lpd.perms \
		--with-printcap_path=/etc/printcap
USE_GMAKE=	yes

MAN1=		cancel.1 lp.1 lpbanner.1 lpf.1 \
		lpq.1 lpr.1 lpraccnt.1 lprm.1 lpstat.1 monitor.1 \
		pclbanner.1 psbanner.1
MAN5=		lpd.conf.5 lpd.perms.5 printcap.5
MAN8=		checkpc.8 lpc.8 lpd.8
MANCOMPRESSED=	yes

post-install:
	${INSTALL} -d -g bin -o bin -m 0555 ${PREFIX}/share/doc/LPRng
	${INSTALL} -c -g bin -o bin -m 0444 ${WRKSRC}/HOWTO/* ${PREFIX}/share/doc/LPRng
	@${CAT} ${PKGMESSAGE} | ${SED} -e "s|@@PREFIX@@|${PREFIX}|g"

.include <bsd.port.mk>
