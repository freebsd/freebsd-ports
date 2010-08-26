# New ports collection makefile for:	scam-backscatter
# Date created:				2010-05-27
# Whom:					Janne Snabb <snabb@epipe.com>
#
# $FreeBSD$
#

PORTNAME=	scam-backscatter
PORTVERSION=	1.5.1
CATEGORIES=	mail
MASTER_SITES=	http://www.elandsys.com/scam/scam-backscatter/ \
		http://dist.epipe.com/mirrors/scam-backscatter/
DISTNAME=	scamback-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	snabb@epipe.com
COMMENT=	Address verification milter to prevent spam backscatter

WRKSRC=		${WRKDIR}/scamback
USE_RC_SUBR=	scam-backscatter
SUB_FILES=	pkg-message

MAKEFILE=	Makefile.freebsd
ALL_TARGET=

OPTIONS=	ALLDOMAINS "Verify any domain with the backend" Off \
		EHLO "Use EHLO instead of HELO in SMTP session" Off \
		USEMAILERTABLE "Use mailertable to map domains to backends" Off

.include <bsd.port.options.mk>
.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

LDFLAGS+=	${SENDMAIL_LDFLAGS}
LIBS+=		-lmilter
LIBS+=		${SENDMAIL_LDADD}

CFLAGS+=	${PTHREAD_CFLAGS}
LIBS+=		${PTHREAD_LIBS}

.if defined(WITH_ALLDOMAINS)
CFLAGS+=	-DALLDOMAINS
.endif
.if defined(WITH_EHLO)
CFLAGS+=	-DEHLO
.endif
.if defined(WITH_USEMAILERTABLE)
CFLAGS+=	-DUSEMAILERTABLE
.endif

MAKE_ARGS+=	CC="${CC}" CCFLAGS="${CFLAGS}" CFLAGS="" \
		LDFLAGS="${LDFLAGS}" LIBS="${LIBS}"

post-patch:
	@${REINPLACE_CMD} -e \
	    's|/var/spool/scam/scam-back\.pid|/var/run/scam-back\.pid|g; \
	    s|/etc/mail/scam\.conf|${PREFIX}/etc/mail/scam-back\.conf|g;' \
	    ${WRKSRC}/scam-back.c

do-install:
	${MKDIR} ${PREFIX}/etc/mail
	${INSTALL_PROGRAM} ${WRKSRC}/scam-back ${PREFIX}/libexec/scam-back
	${INSTALL_DATA} ${WRKSRC}/scam.conf ${PREFIX}/etc/mail/scam-back.conf.sample

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/INSTALL ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/License ${DOCSDIR}
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
