# New ports collection makefile for:	xcdroast
# Date Created:		28 Sep 2000
# Whom:			Oliver Lehmann <Kai_Allard_Liao@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	xcdroast
PORTVERSION=	0.98.a.9
CATEGORIES=	sysutils
MASTER_SITES=	http://www.xcdroast.org/download/
DISTNAME=	${PORTNAME}-0.98alpha9

MAINTAINER=	lehmann@ans-netz.de

RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools \
		mkisofs:${PORTSDIR}/sysutils/mkisofs

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GTK=	yes
USE_IMLIB=	yes

MAKE_ENV+=	GTK_CONFIG="${GTK_CONFIG}" \
		IMLIB_CONFIG="${IMLIB_CONFIG}"

post-patch:
	for i in xcdroast.h Makefile ; do \
	  ${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/$$i ; \
	done

	for i in Makefile ; do \
	  ${PERL} -pi -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/$$i ; \
	done

post-install:
	@${CAT} ${PKGMESSAGE}

enable-nonroot:

	/usr/sbin/pw groupadd -n cdwrite

	for i in cdrecord cdda2wav mkisofs readcd; do \
	    ${CHOWN} root:cdwrite ${LOCALBASE}/bin/$$i ; \
	    ${CHMOD} 4710 ${LOCALBASE}/bin/$$i ; \
	done

	${CHOWN} root:cdwrite ${PREFIX}/lib/xcdroast-0.98/bin/xcdrwrap
	${CHMOD} 2755 ${PREFIX}/lib/xcdroast-0.98/bin/xcdrwrap

	@${ECHO} ""
	@${ECHO} "***************************************************************"
	@${ECHO} " The first time root have to start xcdroast, to create the"
	@${ECHO} " root-configuration-file ${PREFIX}/etc/xcdroast.conf. Without"
	@${ECHO} " this file, a normal user will get an error message."
	@${ECHO} "***************************************************************"
	@${ECHO} ""

.include <bsd.port.mk>
