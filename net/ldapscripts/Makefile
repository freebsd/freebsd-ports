# New ports collection makefile for:	ldapscripts
# Date created:		Sat Oct 01 09:30:00 UTC 2003
# Whom:			Ganael LAPLANCHE <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#

PORTNAME=	ldapscripts
PORTVERSION=	1.9.0
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		http://contribs.martymac.com/ldapscripts/

EXTRACT_SUFX=	.tgz

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	Scripts to manage posix accounts in an OpenLDAP directory

WANT_OPENLDAP_VER?=	23
.if (${WANT_OPENLDAP_VER} != 21) && (${WANT_OPENLDAP_VER} != 22) && (${WANT_OPENLDAP_VER} != 23) && (${WANT_OPENLDAP_VER} != 24)
BROKEN=	Incompatible OpenLDAP version: ${WANT_OPENLDAP_VER}
.endif

RUN_DEPENDS=	ldapadd:${PORTSDIR}/net/openldap${WANT_OPENLDAP_VER}-client \
		ldapsearch:${PORTSDIR}/net/openldap${WANT_OPENLDAP_VER}-client \
		ldapdelete:${PORTSDIR}/net/openldap${WANT_OPENLDAP_VER}-client \
		ldapmodify:${PORTSDIR}/net/openldap${WANT_OPENLDAP_VER}-client \
		ldapmodrdn:${PORTSDIR}/net/openldap${WANT_OPENLDAP_VER}-client \
		ldappasswd:${PORTSDIR}/net/openldap${WANT_OPENLDAP_VER}-client

USE_ICONV=	yes
LIBDIR=${PREFIX}/lib/${PORTNAME}
MAKE_ENV+=	MANDIR=${MANPREFIX}/man \
		ETCDIR=${ETCDIR}

MANLANG=	""
MANCOMPRESSED=	yes
MAN1=	ldapaddgroup.1 ldapaddmachine.1 ldapadduser.1 ldapaddusertogroup.1 \
	ldapdeletegroup.1 ldapdeleteuser.1 ldapdeleteuserfromgroup.1 \
	ldaprenameuser.1 ldapsetprimarygroup.1 lsldap.1 ldaprenamemachine.1 \
	ldaprenamegroup.1 ldapinit.1 ldapdeletemachine.1 ldapsetpasswd.1 \
	ldapfinger.1 ldapgid.1 ldapid.1 ldapmodifygroup.1 ldapmodifymachine.1 \
	ldapmodifyuser.1
MAN5=	ldapscripts.5

PORTDOCS=	README CHANGELOG COPYING VERSION TODO

# Unset 'all' target set by default to 'help'
# and set paths to OpenLDAP binaries
post-patch:
	${REINPLACE_CMD} "s|^all:.*|all:|g" ${WRKSRC}/Makefile
	${REINPLACE_CMD} "s|^PREFIX = .*|PREFIX = ${PREFIX}|g" ${WRKSRC}/Makefile
	${REINPLACE_CMD} \
	-e "s|^LDAPSEARCHBIN=.*|LDAPSEARCHBIN=\"${LOCALBASE}/bin/ldapsearch\"|g" \
	-e "s|^LDAPADDBIN=.*|LDAPADDBIN=\"${LOCALBASE}/bin/ldapadd\"|g" \
	-e "s|^LDAPDELETEBIN=.*|LDAPDELETEBIN=\"${LOCALBASE}/bin/ldapdelete\"|g" \
	-e "s|^LDAPMODIFYBIN=.*|LDAPMODIFYBIN=\"${LOCALBASE}/bin/ldapmodify\"|g" \
	-e "s|^LDAPMODRDNBIN=.*|LDAPMODRDNBIN=\"${LOCALBASE}/bin/ldapmodrdn\"|g" \
	-e "s|^LDAPPASSWDBIN=.*|LDAPPASSWDBIN=\"${LOCALBASE}/bin/ldappasswd\"|g" \
	-e "s|^ICONVBIN=.*|ICONVBIN=\"${LOCALBASE}/bin/iconv\"|g" \
	${WRKSRC}/etc/ldapscripts.conf

# Install remaining stuff
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/VERSION ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
