# ex:ts=8
# Ports collection makefile for:    dhcp
# Date created:         7 Mar 1996
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	dhcp
PORTVERSION=	3.0.1.r9
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_ISC}
MASTER_SITE_SUBDIR=	dhcp dhcp/dhcp-3.0-history
PKGNAMEPREFIX=	isc-
PKGNAMESUFFIX=	3
DISTNAME=	${PORTNAME}-${RELEASE}${VERSION}${PATCHLEVEL}

MAINTAINER=	cyrille.lefevre@laposte.net

USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

# Global variables
#

HAS_CONFIGURE=	yes

MAN1=		omshell.1
MAN3=		dhcpctl.3 omapi.3 omshell.3
MAN5=		dhclient.conf.5 dhclient.leases.5 \
		dhcp-eval.5 dhcp-options.5 dhcpd.conf.5 \
		dhcpd.leases.5
MAN8=		dhclient.8 dhclient-script.8 dhcpd.8 dhcrelay.8

MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

# Local variables
#

# for instance, possible versions are:
#	1.2.r3.4 (or 1.2.b3.4), 1.2.r3 (or 1.2.b3), 1.2.3, 1.2
# which have to become:
#	1.2rc3pl4 (or 1.2beta3pl4), 1.2rc3 (or 1.2beta3), 1.2pl3, 1.2
# so, the magic things are:
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

BIN_FILES=	dhclient dhcpd dhcrelay omshell
CONF_FILES=	dhclient.conf
RC_FILES=	isc-dhcpd isc-dhcrelay
DOC_FILES=	ANONCVS CHANGES COPYRIGHT README RELNOTES
SAMP_FILES=	client/dhclient.conf server/dhcpd.conf
DATA_FILES=	dhclient.leases dhcpd.leases

SAMP_SUFX=	.sample

CONF_DIR=	${PREFIX}/etc
RC_DIR=		${PREFIX}/etc/rc.d
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
DATADIR=	/var/db

STRIP_CMD?=	strip

# Post-patch
#

post-patch: patch-scripts patch-makefile-conf \
	    patch-makefiles-dist patch-man-pages \
	    patch-pkgmessage

patch-scripts:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/client/scripts/freebsd

patch-makefile-conf:
	@${REINPLACE_CMD} -e 's|^DEBUG[ 	]*=|# DEBUG ?=|g' \
		${WRKSRC}/Makefile.conf

patch-makefiles-dist:
.for subdir in ${PATCH_SUBDIRS}
	@${REINPLACE_CMD} -e 's|^CFLAGS[ 	]*=|CFLAGS +=|g' \
		${WRKSRC}/${subdir}/Makefile.dist
.endfor

# temporary hack - no patch file needed for this typo.
patch-man-pages:
	@${REINPLACE_CMD} -e '/^\.Fd$$/d' ${WRKSRC}/dhcpctl/dhcpctl.3

patch-pkgmessage:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g;s|%%MAN1PREFIX%%|${MAN1PREFIX}|g' \
		${MSG_FILE} > ${PKGMESSAGE}

# Post-install
#

post-install: strip-binary-files install-startup-files \
	      install-doc-files install-sample-files \
	      create-conf-files create-data-files \
	      display-message

strip-binary-files:
.for file in ${BIN_FILES}
.if exists(${PREFIX}/bin/${file})
	@${STRIP_CMD} ${PREFIX}/bin/${file}
.endif
.if exists(${PREFIX}/sbin/${file})
	@${STRIP_CMD} ${PREFIX}/sbin/${file}
.endif
.endfor

install-startup-files:
.for file in ${RC_FILES}
.if exists(${FILESDIR}/rc.${file}.conf${SAMP_SUFX})
	@${INSTALL_DATA} ${FILESDIR}/rc.${file}.conf${SAMP_SUFX} ${CONF_DIR}
.if !exists(${CONF_DIR}/rc.${file}.conf)
	@${INSTALL_DATA} ${FILESDIR}/rc.${file}.conf${SAMP_SUFX} \
		${CONF_DIR}/rc.${file}.conf
.endif
.endif
.if exists(${FILESDIR}/${file}.sh${SAMP_SUFX})
	@${INSTALL_SCRIPT} ${FILESDIR}/${file}.sh${SAMP_SUFX} ${RC_DIR}
.endif
.endfor

install-doc-files:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

install-sample-files:
.for file in ${SAMP_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${CONF_DIR}/${file:T}${SAMP_SUFX}
.endfor

create-conf-files:
.for file in ${CONF_FILES}
.if !exists(${CONF_DIR}/${file})
	@${TOUCH} ${CONF_DIR}/${file}
.endif
.endfor

create-data-files:
.for file in ${DATA_FILES}
.if !exists(${DATADIR}/${file})
	@${TOUCH} ${DATADIR}/${file}
.endif
.endfor

display-message:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
