# New ports collection makefile for:   spamass-milter
# Date created:        29 April 2002
# Whom:                Eugene M. Kim <ab@astralblue.net>
#
# $FreeBSD$
#

PORTNAME=	spamass-milter
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	spamass-milt

MAINTAINER=	ab@astralblue.net
COMMENT=	Sendmail Milter (mail filter) for SpamAssassin

BUILD_DEPENDS=	spamc:${PORTSDIR}/mail/p5-Mail-SpamAssassin
RUN_DEPENDS=	spamc:${PORTSDIR}/mail/p5-Mail-SpamAssassin

#
# You can choose the sendmail to be used by specifying
#
# WITH_SENDMAIL_BASE=yes
#  or
# WITH_SENDMAIL_PORT=yes
#

# if no preference was set, check for an up to date base version
# but give an installed port preference over it.

.include <bsd.port.pre.mk>

.if !defined(WITH_SENDMAIL_BASE) && \
    !defined(WITH_SENDMAIL_PORT) && \
    !exists(${LOCALBASE}/lib/libmilter.a)
WITH_SENDMAIL_BASE=yes
.endif

.if defined(WITH_SENDMAIL_BASE)
.if exists(/usr/lib/libmilter.a)
MILTERBASE=	/usr
.else
BROKEN=	"Base system sendmail not found or too old, rebuild with WITH_SENDMAIL_PORT=yes"
.endif
.else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmilter.a:${PORTSDIR}/mail/sendmail
MILTERBASE?=	${LOCALBASE}
.endif

MILTERINC=	${MILTERBASE}/include
MILTERLIB=	${MILTERBASE}/lib

CPPFLAGS+=	-I${MILTERINC}
LDFLAGS+=	-L${MILTERLIB}

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

USE_AUTOCONF_VER= 253
USE_AUTOMAKE_VER= 15

MAN1=		spamass-milter.1

post-patch:
.for f in spamass-milter.sh.dist activation.txt
	${SED} -e 's|/usr/local|${PREFIX}|g' \
		${FILESDIR}/${f} > ${WRKDIR}/${f}
.endfor

post-install:
	${INSTALL_DATA} ${WRKDIR}/spamass-milter.sh.dist \
		${PREFIX}/etc/rc.d/spamass-milter.sh.dist
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/activation.txt ${DOCSDIR}/activation.txt
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
