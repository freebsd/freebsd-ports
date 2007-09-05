# New ports collection makefile for:	ldapscripts
# Date created:		Sat Oct 01 09:30:00 UTC 2003
# Whom:			Ganael LAPLANCHE <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#

PORTNAME=	ldapscripts
PORTVERSION=	1.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://contribs.martymac.com/ldapscripts/
MASTER_SITE_SUBDIR=	ldapscripts
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
		_ldaprenamegroup.1 _ldapinit.1 _ldapdeletemachine.1 _ldappasswd.1 _ldapfinger.1 \
		_ldapmodifygroup.1 _ldapmodifymachine.1 _ldapmodifyuser.1
MAN5=	ldapscripts.5

PORTDOCS=	README CHANGELOG COPYING VERSION TODO

# Change /etc to ${PREFIX}/etc
post-patch:
	${REINPLACE_CMD} -E -e "s|^_RUNTIMEFILE=.*|_RUNTIMEFILE=\"${ETCDIR}/runtime\"|g" ${WRKSRC}/bin/*
	${REINPLACE_CMD} -E -e "s|^_CONFIGFILE=.*|_CONFIGFILE=\"${ETCDIR}/ldapscripts.conf\"|g" ${WRKSRC}/etc/runtime

	${REINPLACE_CMD} -E -e "s|^LDAPSEARCHBIN=.*|LDAPSEARCHBIN=\"${PREFIX}/bin/ldapsearch\"|g" ${WRKSRC}/etc/ldapscripts.conf
	${REINPLACE_CMD} -E -e "s|^LDAPADDBIN=.*|LDAPADDBIN=\"${PREFIX}/bin/ldapadd\"|g" ${WRKSRC}/etc/ldapscripts.conf
	${REINPLACE_CMD} -E -e "s|^LDAPDELETEBIN=.*|LDAPDELETEBIN=\"${PREFIX}/bin/ldapdelete\"|g" ${WRKSRC}/etc/ldapscripts.conf
	${REINPLACE_CMD} -E -e "s|^LDAPMODIFYBIN=.*|LDAPMODIFYBIN=\"${PREFIX}/bin/ldapmodify\"|g" ${WRKSRC}/etc/ldapscripts.conf
	${REINPLACE_CMD} -E -e "s|^LDAPMODRDNBIN=.*|LDAPMODRDNBIN=\"${PREFIX}/bin/ldapmodrdn\"|g" ${WRKSRC}/etc/ldapscripts.conf
	${REINPLACE_CMD} -E -e "s|^LDAPPASSWDBIN=.*|LDAPPASSWDBIN=\"${PREFIX}/bin/ldappasswd\"|g" ${WRKSRC}/etc/ldapscripts.conf

# Just copy the scripts
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/_ldapdeletemachine ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/_ldapinit ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/_lsldap ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ldapaddgroup ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ldapadduser ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ldapdeletegroup ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ldapdeleteuserfromgroup ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ldapsetprimarygroup ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ldapaddmachine ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ldapaddusertogroup ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ldapdeleteuser ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ldaprenameuser ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/_ldaprenamegroup ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/_ldaprenamemachine ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/_ldappasswd ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/_ldapfinger ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/_ldapmodifyuser ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/_ldapmodifygroup ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/_ldapmodifymachine ${PREFIX}/bin

	${MKDIR} ${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/ldapscripts.conf ${ETCDIR}/ldapscripts.conf.sample
	if [ ! -f ${ETCDIR}/ldapscripts.conf ]; then \
		${CP} -p ${ETCDIR}/ldapscripts.conf.sample ${ETCDIR}/ldapscripts.conf; \
	fi
	${INSTALL_DATA} ${WRKSRC}/etc/runtime ${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/ldapaddgroup.template.sample ${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/ldapadduser.template.sample ${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/ldapaddmachine.template.sample ${ETCDIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/VERSION ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${DOCSDIR}
.endif

	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/man5/* ${MAN5PREFIX}/man/man5

.include <bsd.port.mk>
