# New ports collection makefile for:	qpopper
# Date created:		1 April 1995
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	qpopper
PORTVERSION= 	3.1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.qualcomm.com/eudora/servers/unix/popper/ \
		ftp://ftp.gmxuk.net/pub/qpopper/ \
		ftp://sunsite.doc.ic.ac.uk/Mirrors/ftp.qualcomm.com/eudora/servers/unix/popper/ \
		ftp://ftp.kracked.com/pub/qpopper/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	jeff@isni.net

# If APOP_ONLY variable present in the environment, popper builds
# with APOP authentification only.
#
# If FULL_POPD_DEBUG variable present in the environment, popper builds
# with more verbose debugging.

.if defined(APOP_ONLY)
OS_DEFS+=	-DAPOP_ONLY
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-lmd -lutil" \
		OS_DEFS="-DSETPROCTITLE -DBSD44_DBM ${OS_DEFS}"
CONFIGURE_ARGS=	--enable-apop=${PREFIX}/etc/qpopper/pop.auth \
		--enable-nonauth-file=/etc/ftpusers \
		--with-apopuid=pop \
		--enable-keep-temp-drop

# Set FULL_POPD_DEBUG for debug-mode. See also -d option to popper
.if defined(FULL_POPD_DEBUG)
CONFIGURE_ARGS+=--enable-debugging
.endif

MAN8=		qpopauth.8 qpopper.8

post-patch:
	@$(RM) -f ${WRKSRC}/popper/md5.h
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/man/*

do-install:
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} popper/popauth ${PREFIX}/bin/qpopauth && \
		${INSTALL_PROGRAM} popper/popper ${PREFIX}/libexec/qpopper && \
		${INSTALL_MAN} man/popauth.8 ${PREFIX}/man/man8/qpopauth.8 && \
		${INSTALL_MAN} man/popper.8 ${PREFIX}/man/man8/qpopper.8
	${LN} -sf ${PREFIX}/bin/qpopauth ${PREFIX}/bin/qapopauth

post-install:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGMESSAGE}

.include <bsd.port.mk>
