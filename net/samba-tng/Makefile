# New ports collection makefile for:	samba-tng
# Date created:				11th May 2002
# Whom:					dwcjr
#
# $FreeBSD$
#

PORTNAME=	samba-tng
PORTVERSION=	2.6.1c20020524
CATEGORIES=	net
MASTER_SITES=	http://www.samba-tng.org/download/tng/ \
		http://something.inethouston.net/~poseiden/
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}_0.${PORTVERSION:S,c,cvs,}

MAINTAINER=	dwcjr@FreeBSD.org

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

GNU_CONFIGURE=	YES
INSTALLS_SHLIB=	YES
USE_GMAKE=	YES
USE_BZIP2=	YES
USE_SUBMAKE=	YES
USE_AUTOCONF=	YES
WRKSRC=		${WRKDIR}/tng-clean/source

# directories
VARDIR=		/var
SAMBA_SPOOL=	${VARDIR}/spool/samba
SAMBA_LOGDIR=	${VARDIR}/log
SAMBA_PRIVATE=	${PREFIX}/private
SAMBA_CONFDIR=	${PREFIX}/etc

CONFIGURE_ARGS=	--localstatedir=${VARDIR}/lock \
		--with-privatedir=${SAMBA_PRIVATE} --with-pam \
		--with-logdir=${VARDIR}/log --with-tmpdir=${VARDIR}/run/samba-tng \
		--with-libiconv=${LOCALBASE}

MAN1=		debug2html.1 make_smbcodepage.1 nmblookup.1 \
		regedit.1 rpcclient.1 smbclient.1 smbrun.1 \
		smbstatus.1 smbtar.1 testparm.1 testprns.1 \
		wbinfo.1

MAN5=		lmhosts.5 smb.conf.5 smbpasswd.5

MAN7=		samba.7

MAN8=		browserd.8 lsarpcd.8 netlogond.8 nmbd.8 rpcclient.8 \
		samedit.8 samrd.8 smbd.8 smbmnt.8 smbmount.8 \
		smbpasswd.8 smbspool.8 smbumount.8 spoolssd.8 \
		srvsvcd.8 svcctld.8 swat.8 winbindd.8 winregd.8 \
		wkssvcd.8

.include<bsd.port.pre.mk>

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \
		CAT="${CAT}" \
		SAMBA_OPTIONS="${SAMBA_OPTIONS}" \
		REALCURDIR="${.CURDIR}"

.if defined(WITH_SYSLOG)
CONFIGURE_ARGS+=	--with-syslog
.endif

.if defined(WITH_MSDFS)
CONFIGURE_ARGS+=	--with-msdfs
.endif

.if defined(WITH_LDAP)
LIB_DEPENDS+=		ldap.2:${PORTSDIR}/net/openldap2
CONFIGURE_ARGS+=	--with-ldapsam
CONFIGURE_ENV+=		CPPFLAGS=-I${LOCALBASE}/include \
			LDFLAGS=-L${LOCALBASE}/lib
.endif

.if !defined(WITHOUT_CUPS)
WITH_CUPS=	yes
.endif

.if defined(WITH_CUPS)
LIB_DEPENDS+=		cups.2:${PORTSDIR}/print/cups-base
CONFIGURE_ENV+=		CPPFLAGS=-I${LOCALBASE}/include \
			LDFLAGS=-L${LOCALBASE}/lib
.endif

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.samba

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/script/samba-init.d ${SAMBA_CONFDIR}/rc.d/samba-tng.sh.sample

.include <bsd.port.post.mk>
