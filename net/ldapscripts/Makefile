# New ports collection makefile for:	ldapscripts
# Date created:		Sat Oct 01 09:30:00 UTC 2003
# Whom:			Ganael LAPLANCHE <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#

PORTNAME=	ldapscripts
PORTVERSION=	1.6
CATEGORIES=	net
MASTER_SITES=	http://contribs.martymac.com/ldapscripts/ \
				${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	Scripts to manage posix accounts in an OpenLDAP directory

NO_BUILD=	yes

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

MANLANG=	""
MANCOMPRESSED=	no
MAN1=	ldapaddgroup.1 ldapaddmachine.1 ldapadduser.1 ldapaddusertogroup.1 \
		ldapdeletegroup.1 ldapdeleteuser.1 ldapdeleteuserfromgroup.1 \
		ldaprenameuser.1 ldapsetprimarygroup.1 _lsldap.1 _ldaprenamemachine.1 \
		_ldaprenamegroup.1 _ldapinit.1 _ldapdeletemachine.1 _ldappasswd.1 _ldapfinger.1
MAN5=	ldapscripts.5

# Change /etc to ${LOCALBASE}/etc
post-patch:
	${REINPLACE_CMD} -E -e "s|^_RUNTIMEFILE=.*|_RUNTIMEFILE=\"${LOCALBASE}/etc/ldapscripts/runtime\"|g" ${WRKSRC}/bin/*
	${REINPLACE_CMD} -E -e "s|^_CONFIGFILE=.*|_CONFIGFILE=\"${LOCALBASE}/etc/ldapscripts/ldapscripts.conf\"|g" ${WRKSRC}/etc/runtime

	${REINPLACE_CMD} -E -e "s|^LDAPSEARCHBIN=.*|LDAPSEARCHBIN=\"${LOCALBASE}/bin/ldapsearch\"|g" ${WRKSRC}/etc/ldapscripts.conf
	${REINPLACE_CMD} -E -e "s|^LDAPADDBIN=.*|LDAPADDBIN=\"${LOCALBASE}/bin/ldapadd\"|g" ${WRKSRC}/etc/ldapscripts.conf
	${REINPLACE_CMD} -E -e "s|^LDAPDELETEBIN=.*|LDAPDELETEBIN=\"${LOCALBASE}/bin/ldapdelete\"|g" ${WRKSRC}/etc/ldapscripts.conf
	${REINPLACE_CMD} -E -e "s|^LDAPMODIFYBIN=.*|LDAPMODIFYBIN=\"${LOCALBASE}/bin/ldapmodify\"|g" ${WRKSRC}/etc/ldapscripts.conf
	${REINPLACE_CMD} -E -e "s|^LDAPMODRDNBIN=.*|LDAPMODRDNBIN=\"${LOCALBASE}/bin/ldapmodrdn\"|g" ${WRKSRC}/etc/ldapscripts.conf
	${REINPLACE_CMD} -E -e "s|^LDAPPASSWDBIN=.*|LDAPPASSWDBIN=\"${LOCALBASE}/bin/ldappasswd\"|g" ${WRKSRC}/etc/ldapscripts.conf

# Just copy the scripts
do-install:
	${CP} ${WRKSRC}/bin/_ldapdeletemachine ${PREFIX}/bin
	${CP} ${WRKSRC}/bin/_ldapinit ${PREFIX}/bin
	${CP} ${WRKSRC}/bin/_lsldap ${PREFIX}/bin
	${CP} ${WRKSRC}/bin/ldapaddgroup ${PREFIX}/bin
	${CP} ${WRKSRC}/bin/ldapadduser ${PREFIX}/bin
	${CP} ${WRKSRC}/bin/ldapdeletegroup ${PREFIX}/bin
	${CP} ${WRKSRC}/bin/ldapdeleteuserfromgroup ${PREFIX}/bin
	${CP} ${WRKSRC}/bin/ldapsetprimarygroup ${PREFIX}/bin
	${CP} ${WRKSRC}/bin/ldapaddmachine ${PREFIX}/bin
	${CP} ${WRKSRC}/bin/ldapaddusertogroup ${PREFIX}/bin
	${CP} ${WRKSRC}/bin/ldapdeleteuser ${PREFIX}/bin
	${CP} ${WRKSRC}/bin/ldaprenameuser ${PREFIX}/bin
	${CP} ${WRKSRC}/bin/_ldaprenamegroup ${PREFIX}/bin
	${CP} ${WRKSRC}/bin/_ldaprenamemachine ${PREFIX}/bin
	${CP} ${WRKSRC}/bin/_ldappasswd ${PREFIX}/bin
	${CP} ${WRKSRC}/bin/_ldapfinger ${PREFIX}/bin

	${MKDIR} ${LOCALBASE}/etc/ldapscripts
	if [ -f ${LOCALBASE}/etc/ldapscripts/ldapscripts.conf ]; then \
		${CP} ${LOCALBASE}/etc/ldapscripts/ldapscripts.conf ${LOCALBASE}/etc/ldapscripts/ldapscripts.conf.old; \
	fi
	${CP} ${WRKSRC}/etc/ldapscripts.conf ${LOCALBASE}/etc/ldapscripts
	${CP} ${WRKSRC}/etc/runtime ${LOCALBASE}/etc/ldapscripts
	${CP} ${WRKSRC}/etc/ldapaddgroup.template.sample ${LOCALBASE}/etc/ldapscripts
	${CP} ${WRKSRC}/etc/ldapadduser.template.sample ${LOCALBASE}/etc/ldapscripts
	${CP} ${WRKSRC}/etc/ldapaddmachine.template.sample ${LOCALBASE}/etc/ldapscripts
	${CP} ${WRKSRC}/README ${LOCALBASE}/etc/ldapscripts
	${CP} ${WRKSRC}/CHANGELOG ${LOCALBASE}/etc/ldapscripts
	${CP} ${WRKSRC}/COPYING ${LOCALBASE}/etc/ldapscripts
	${CP} ${WRKSRC}/VERSION ${LOCALBASE}/etc/ldapscripts
	${CP} ${WRKSRC}/TODO ${LOCALBASE}/etc/ldapscripts

	${CP} ${WRKSRC}/man/man1/* ${MANPREFIX}/man/man1
	${CP} ${WRKSRC}/man/man5/* ${MANPREFIX}/man/man5

.include <bsd.port.mk>
