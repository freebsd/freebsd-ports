# ex:ts=8
# New ports collection makefile for:	fcron
# Date created:			Mar 1, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fcron
PORTVERSION=	2.1.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://fcron.free.fr/
MASTER_SITE_SUBDIR=	system/daemons/cron
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	svenasse@polaris.ca
COMMENT=	Fcron is a periodical command scheduler

NO_PACKAGE=	"Runaway package build"

USE_AUTOCONF_VER=	213
USE_PERL5=	yes
CONFIGURE_ARGS=	--with-etcdir=${PREFIX}/etc --with-cflags="${CFLAGS}" \
		--with-rootname=root --with-rootgroup=wheel \
		--with-answer-all=yes

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--with-docdir=${DOCSDIR}
PLIST_SUB=	PORTVERSION=${PORTVERSION}
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=	fcrontab.1
MAN3=	bitstring.3
MAN5=	fcrontab.5 fcron.conf.5
MAN8=	fcron.8

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/FAQ ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/files/fcron.pam ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/files/fcrontab.pam ${DOCSDIR}
.endif
.for i in allow deny conf
.if !exists(${PREFIX}/etc/fcron.$i)
	@${CP} -p ${PREFIX}/etc/fcron.$i.dist ${PREFIX}/etc/fcron.$i
.endif
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
