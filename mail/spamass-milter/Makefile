# New ports collection makefile for:   spamass-milter
# Date created:        29 April 2002
# Whom:                Eugene M. Kim <ab@astralblue.net>
#
# $FreeBSD$
#

PORTNAME=	spamass-milter
PORTVERSION=	0.3.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	spamass-milt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sendmail Milter (mail filter) plugin for SpamAssassin

BUILD_DEPENDS=	spamc:${PORTSDIR}/mail/p5-Mail-SpamAssassin
RUN_DEPENDS=	spamc:${PORTSDIR}/mail/p5-Mail-SpamAssassin

##
# Use the following quirks to choose which sendmail to use (ports or system):
#
#   WITH_SENDMAIL_BASE=yes
# or
#   WITH_SENDMAIL_PORT=yes
#
# If unspecified, check for an up-to-date system version but give an
# installed port preference over it.
#

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libldap.so)
WITH_LDAP=yes
.endif

.if !defined(WITHOUT_LDAP) && defined(WITH_LDAP)
USE_OPENLDAP=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

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

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS ChangeLog NEWS README TODO
.endif

MILTERINC=	${MILTERBASE}/include
MILTERLIB=	${MILTERBASE}/lib

CPPFLAGS+=	-I${MILTERINC}
LDFLAGS+=	-L${MILTERLIB}

USE_REINPLACE=	yes
USE_RC_SUBR=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

PKGMESSAGE=	${WRKDIR}/pkg-message

MAN1=		spamass-milter.1

post-patch:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/spamass-milter.sh > ${WRKDIR}/spamass-milter.sh
	@${SED} -e's,%%PREFIX%%,${PREFIX},g' \
		${FILESDIR}/activation.txt > ${WRKDIR}/activation.txt
.if !defined(WITHOUT_LDAP) && defined(WITH_LDAP)
	@${REINPLACE_CMD} -e 's|-lmilter|-lmilter -lldap|g' ${WRKSRC}/configure
.endif
	@${SED} -e's,%%DOCSDIR%%,${DOCSDIR},g' \
		${MASTERDIR}/pkg-message > ${PKGMESSAGE}

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/spamass-milter.sh ${PREFIX}/etc/rc.d/spamass-milter.sh
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/activation.txt ${DOCSDIR}/activation.txt
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
