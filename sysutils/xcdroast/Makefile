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

post-patch:
	for i in xcdroast.h Makefile ; do \
	  ${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/$$i ; \
	done

post-install:

	${LN} -sf ${LOCALBASE}/bin/cdrecord ${PREFIX}/lib/xcdroast-0.98/bin/cdrecord
	${LN} -sf ${LOCALBASE}/bin/mkisofs ${PREFIX}/lib/xcdroast-0.98/bin/mkisofs
	${LN} -sf ${LOCALBASE}/bin/cdda2wav ${PREFIX}/lib/xcdroast-0.98/bin/cdda2wav
	${LN} -sf ${LOCALBASE}/bin/readcd ${PREFIX}/lib/xcdroast-0.98/bin/readcd

	/usr/sbin/pw groupadd -n cdwrite

	for i in cdrecord cdda2wav mkisofs readcd ; do \
	    ${CHOWN} root:cdwrite ${PREFIX}/bin/$i && \
	    ${CHMOD} 4710 ${PREFIX}/bin/$i ; \
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
