# ex:ts=8
# Ports collection makefile for:    dhcp
# Date created:         7 Mar 1996
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	dhcp
PORTVERSION=	3.0.b2.24
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/dhcp/
PKGNAMEPREFIX=	isc-
PKGNAMESUFFIX=	3
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/b/:R}pl${PORTVERSION:E}

MAINTAINER=	clefevre@poboxes.com

#
# Global variables
#

HAS_CONFIGURE=	yes

MAN3=		dhcpctl.3 omapi.3
MAN5=		dhclient.conf.5 dhclient.leases.5 dhcp-contrib.5 \
		dhcp-eval.5 dhcp-options.5 dhcpd.conf.5 \
		dhcpd.leases.5
MAN8=		dhclient.8 dhclient-script.8 dhcpd.8 dhcrelay.8

#
# Local variables
#

PATCH_SUBDIRS=	common minires dst omapip server client relay dhcpctl

BIN_FILES=	dhclient dhcpd dhcrelay
SAMP_FILES=	client/dhclient.conf server/dhcpd.conf
RCD_FILES=	isc-dhcpd.sh.sample
DOC_FILES=	CHANGES COPYRIGHT README RELNOTES
DATA_FILES=	dhclient.leases dhcpd.leases
CONF_FILES=	dhclient.conf

BIN_DIR=	${PREFIX}/sbin
ETC_DIR=	${PREFIX}/etc
RCD_DIR=	${PREFIX}/etc/rc.d
DOC_DIR=	${PREFIX}/share/doc/${PKGBASE}
VARDB_DIR=	/var/db
VARRUN_DIR=	/var/run

STRIP?=		strip

#
# Post-patch
#

post-patch: patch-scripts patch-makefile-conf patch-makefiles-dist

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

#
# Post-install
#

post-install: strip-binary-files install-startup-files \
	      install-doc-files install-sample-files \
	      create-data-files create-conf-files

strip-binary-files:
.for file in ${BIN_FILES}
.if exists({BIN_DIR}/${file})
	@${STRIP} ${BIN_DIR}/${file}
.endif
.endfor

install-startup-files:
.for file in ${RCD_FILES}
	@${INSTALL_SCRIPT} ${FILESDIR}/${file} ${RCD_DIR}/${file}
.endfor

install-doc-files:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOC_DIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOC_DIR}/${file}
.endfor
.endif

install-sample-files:
.for file in ${SAMP_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${ETC_DIR}/${file:T}.sample
.endfor

create-data-files:
.for file in ${DATA_FILES}
.if !exists(${VARDB_DIR}/${file})
	@${TOUCH} ${VARDB_DIR}/${file}
.endif
.endfor

create-conf-files:
.for file in ${CONF_FILES}
.if !exists(${ETC_DIR}/${file})
	@${TOUCH} ${ETC_DIR}/${file}
.endif
.endfor

.include <bsd.port.mk>
