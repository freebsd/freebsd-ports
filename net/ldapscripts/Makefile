# New ports collection makefile for:	ldapscripts
# Date created:		Sat Oct 01 09:30:00 UTC 2003
# Whom:			Ganael LAPLANCHE <ganael.laplanche@martymac.org>
#
# $FreeBSD$
#

PORTNAME=	ldapscripts
PORTVERSION=	1.10.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		http://contribs.martymac.org/ldapscripts/
EXTRACT_SUFX=	.tgz

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Scripts to manage posix accounts in an OpenLDAP directory

RUN_DEPENDS=	ldapadd:${PORTSDIR}/net/openldap${OPENLDAP_VER}-client \
		ldapsearch:${PORTSDIR}/net/openldap${OPENLDAP_VER}-client \
		ldapdelete:${PORTSDIR}/net/openldap${OPENLDAP_VER}-client \
		ldapmodify:${PORTSDIR}/net/openldap${OPENLDAP_VER}-client \
		ldapmodrdn:${PORTSDIR}/net/openldap${OPENLDAP_VER}-client \
		ldappasswd:${PORTSDIR}/net/openldap${OPENLDAP_VER}-client

LICENSE=	GPLv2

USE_OPENLDAP=	yes
USE_ICONV=	yes
LIBDIR=	${PREFIX}/lib/${PORTNAME}
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

PORTDOCS=	README CHANGELOG VERSION TODO

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
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
