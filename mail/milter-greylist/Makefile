# New ports collection makefile for:	milter-greylist
# Date created:				27 Apr 2004
# Whom:					Cyril Guibourg
#
# $FreeBSD$
#

PORTNAME=	milter-greylist
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.espci.fr/pub/milter-greylist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	aragorn+ports@teaser.fr
COMMENT=	Easy-to-use greylist milter for sendmail

MAN5=		greylist.conf.5
MAN8=		milter-greylist.8

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--with-user=smmsp

ALL_TARGET=	milter-greylist

USE_RC_SUBR=	yes
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

post-extract:
	@${SED}	${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/milter-greylist.sh > ${WRKSRC}/milter-greylist.sh

post-install:
	@${MKDIR} /var/milter-greylist /var/db/milter-greylist
	@${CHOWN} smmsp /var/milter-greylist /var/db/milter-greylist
	@${MKDIR} ${PREFIX}/etc/rc.d
	@${INSTALL_SCRIPT} ${WRKSRC}/milter-greylist.sh ${PREFIX}/etc/rc.d/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/greylist.conf ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
