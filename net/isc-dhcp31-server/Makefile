# ex:ts=8
# Ports collection makefile for:    dhcp
# Date created:         7 Mar 1996
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	dhcp
PORTVERSION=	3.0.r10
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/%SUBDIR%/ \
		${US_MASTER_SITES} ${JAPAN_MASTER_SITES} \
		${AUSTRIA_MASTER_SITES} ${FRANCE_MASTER_SITES} \
		${FINLAND_MASTER_SITES} ${GERMANY_MASTER_SITES} \
		${HUNGARY_MASTER_SITES} ${ICELAND_MASTER_SITES} \
		${LATVIA_MASTER_SITES} ${POLAND_MASTER_SITES} \
		${RUSSIA_MASTER_SITES} ${SPAIN_MASTER_SITES} \
		${SWEDEN_MASTER_SITES} ${UK_MASTER_SITES} \
		${NETHERLANDS_MASTER_SITES} ${BRAZIL_MASTER_SITES} \
		${GREECE_MASTER_SITES} ${TURKEY_MASTER_SITES}
MASTER_SITE_SUBDIR=	dhcp dpcp/dhcp-3.0-history
PKGNAMEPREFIX=	isc-
PKGNAMESUFFIX=	3
DISTNAME=	${PORTNAME}-${RELEASE}${VERSION}${PATCHLEVEL}

MAINTAINER=	clefevre@redirect.to

#
# Global variables
#

FETCH_BEFORE_ARGS+=	-p

HAS_CONFIGURE=	yes

PLIST_SUB=	DATA_DIR="${DATA_DIR}" RCD_SUBDIR="${RCD_SUBDIR}" \
		CONF_SUBDIR="${CONF_SUBDIR}" SAMP_SUBDIR="${SAMP_SUBDIR}" \
		BIN_SUBDIR="${BIN_SUBDIR}" SBIN_SUBDIR="${SBIN_SUBDIR}" \
		INC_SUBDIR="${INC_SUBDIR}" LIB_SUBDIR="${LIB_SUBDIR}" \
		DOC_SUBDIR="${DOC_SUBDIR}" SAMP_SUFFIX="${SAMP_SUFFIX}"

MAN1=		omshell.1
MAN3=		dhcpctl.3 omapi.3 omshell.3
MAN5=		dhclient.conf.5 dhclient.leases.5 dhcp-contrib.5 \
		dhcp-eval.5 dhcp-options.5 dhcpd.conf.5 \
		dhcpd.leases.5
MAN8=		dhclient.8 dhclient-script.8 dhcpd.8 dhcrelay.8

#
# Local variables
#

# fast
AUSTRIA_MASTER_SITES=	ftp://gd.tuwien.ac.at/infosys/servers/isc/%SUBDIR%/
FRANCE_MASTER_SITES=	ftp://ftp.ciril.fr/pub/isc/%SUBDIR%/ \
			ftp://ftp.grolier.fr/pub/isc/%SUBDIR%/
FINLAND_MASTER_SITES=	ftp://ftp.funet.fi/pub/mirrors/ftp.isc.org/isc/%SUBDIR%/
GERMANY_MASTER_SITES=	ftp://ftp.freenet.de/pub/ftp.isc.org/isc/%SUBDIR%/ \
			ftp://ftp.gigabell.net/pub/%SUBDIR%/
HUNGARY_MASTER_SITES=	ftp://ftp.fsn.hu/pub/isc/%SUBDIR%/
ICELAND_MASTER_SITES=	ftp://ftp.gm.is/pub/isc/%SUBDIR%/
JAPAN_MASTER_SITES=	ftp://ftp.kyushu-u.ac.jp/pub/Net/isc/%SUBDIR%/ \
			ftp://ftp.iij.ad.jp/pub/network/isc/%SUBDIR%/ \
			ftp://ftp.u-aizu.ac.jp/pub/net/isc/%SUBDIR%/
LATVIA_MASTER_SITES=	ftp://ftp.linux.lv/pub/software/isc/%SUBDIR%/
POLAND_MASTER_SITES=	ftp://ftp.task.gda.pl/mirror/ftp.isc.org/isc/%SUBDIR%/
RUSSIA_MASTER_SITES=	ftp://ftp.cdu.elektra.ru/pub/unix/isc/%SUBDIR%/
SPAIN_MASTER_SITES=	ftp://ftp.si.uniovi.es/mirror/isc/%SUBDIR%/
SWEDEN_MASTER_SITES=	ftp://ftp.sunet.se/pub/network/isc/%SUBDIR%/ \
			ftp://ftp.chl.chalmers.se/pub/unix/network/isc/%SUBDIR%/
UK_MASTER_SITES=	ftp://unix.hensa.ac.uk/mirrors/ftp.isc.org/isc/%SUBDIR%/
US_MASTER_SITES=	ftp://ftp.epix.net/pub/isc/%SUBDIR%/ \
			ftp://ftp.nominum.com/pub/isc/%SUBDIR%/
NETHERLANDS_MASTER_SITES=	ftp://ftp.ripe.net/mirrors/sites/ftp.isc.org/isc/%SUBDIR%/ \
			ftp://ftp.nl.uu.net/pub/mirrors/ftp.isc.org/%SUBDIR%/

# slow
BRAZIL_MASTER_SITES=	ftp://ftp.pop-mg.com.br/pub/isc/%SUBDIR%/
GREECE_MASTER_SITES=	ftp://ftp.ntua.gr/pub/net/isc/isc/%SUBDIR%/
TURKEY_MASTER_SITES=	ftp://ftp.ulak.net.tr/pub/networking/isc/%SUBDIR%/ \
			ftp://ftp.metu.edu.tr/pub/mirrors/ftp.isc.org/%SUBDIR%/

# for instance, possible version formats are, in order:
#	1.2.r3.4 (or 1.2.b3.4), 1.2.r3 (or 1.2.b3), 1.2.3, 1.2
# which have to become:
#	1.2rc3pl4 (or 1.2beta3pl4), 1.2rc3 (or 1.2beta3), 1.2pl3, 1.2
VERSION=
PATCHLEVEL=
.if ${PORTVERSION:R:E:M[br]*} != ""
RELEASE=	${PORTVERSION:R:R}
VERSION=	${PORTVERSION:R:E:S/b/beta/:S/r/rc/}
PATCHLEVEL=	pl${PORTVERSION:E}
.elif ${PORTVERSION:E:M[br]*} != ""
RELEASE=	${PORTVERSION:R}
VERSION=	${PORTVERSION:E:S/b/beta/:S/r/rc/}
.elif ${PORTVERSION:R:E} != ""
RELEASE=	${PORTVERSION:R}
PATCHLEVEL=	pl${PORTVERSION:E}
.else
RELEASE=	${PORTVERSION}
.endif

PATCH_SUBDIRS=	common minires dst omapip server client relay dhcpctl

SAMP_SUFFIX=	.sample

BIN_FILES=	dhclient dhcpd dhcrelay
CONF_FILES=	dhclient.conf
SAMP_FILES=	client/dhclient.conf server/dhcpd.conf
RCD_FILES=	isc-dhcpd.sh${SAMP_SUFFIX}
DOC_FILES=	CHANGES COPYRIGHT README RELNOTES
DATA_FILES=	dhclient.leases dhcpd.leases

BIN_SUBDIR=	bin
SBIN_SUBDIR=	sbin
CONF_SUBDIR=	etc
SAMP_SUBDIR=	${CONF_SUBDIR}
RCD_SUBDIR=	etc/rc.d
INC_SUBDIR=	include
LIB_SUBDIR=	lib
DOC_SUBDIR=	share/doc/${PKGBASE}
DATA_DIR=	/var/db

STRIP_CMD?=	strip

#
# Post-patch
#

post-patch: patch-scripts patch-makefile-conf patch-makefiles-dist \
	    patch-man-pages

patch-scripts:
	@${PERL} -pi.fbsd -e 's.!!PREFIX!!.${PREFIX}.g' \
		${WRKSRC}/client/scripts/freebsd

patch-makefile-conf:
	@${PERL} -pi.fbsd -e 's|^DEBUG[ 	]*=|# DEBUG ?=|g' \
		${WRKSRC}/Makefile.conf

patch-makefiles-dist:
.for subdir in ${PATCH_SUBDIRS}
	@${PERL} -pi.fbsd -e 's|^CFLAGS[ 	]*=|CFLAGS +=|g' \
		${WRKSRC}/${subdir}/Makefile.dist
.endfor

# temporary hack - no patch file needed for this typo.
patch-man-pages:
	@${PERL} -ni.fbsd -e '/^\.Fd$$/ or print;' ${WRKSRC}/dhcpctl/dhcpctl.3

#
# Post-install
#

post-install: strip-binary-files install-startup-files \
	      install-doc-files install-sample-files \
	      create-data-files create-conf-files

strip-binary-files:
.for file in ${BIN_FILES}
.if exists(${PREFIX}/${BIN_SUBDIR}/${file})
	@${STRIP_CMD} ${PREFIX}/${BIN_SUBDIR}/${file}
.endif
.endfor

install-startup-files:
.for file in ${RCD_FILES}
	@${INSTALL_SCRIPT} ${FILESDIR}/${file} ${PREFIX}/${RCD_SUBDIR}
.endfor

install-doc-files:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${DOC_SUBDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/${DOC_SUBDIR}
.endfor
.endif

install-sample-files:
.for file in ${SAMP_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} \
		${PREFIX}/${SAMP_SUBDIR}/${file:T}${SAMP_SUFFIX}
.endfor

create-data-files:
.for file in ${DATA_FILES}
.if !exists(${DATA_DIR}/${file})
	@${TOUCH} ${DATA_DIR}/${file}
.endif
.endfor

create-conf-files:
.for file in ${CONF_FILES}
.if !exists(${PREFIX}/${CONF_SUBDIR}/${file})
	@${TOUCH} ${PREFIX}/${CONF_SUBDIR}/${file}
.endif
.endfor

.include <bsd.port.mk>
