# New ports collection makefile for:	ezmlm-idx
# Date created:		28 November 1998
# Whom:			Neil Blakey-Milner <nbm@rucus.ru.ac.za>
#
# $FreeBSD$
#

PORTNAME=	ezmlm-idx
PORTVERSION=	0.444
CATEGORIES=	mail
MASTER_SITES=	http://www.ezmlm.org/archive/${PORTVERSION}/ \
		http://ezmlm.sericyb.com.au/archive/${PORTVERSION}/ \
		http://cr.yp.to/software/ \
		http://gd.tuwien.ac.at/infosys/mail/qmail/ezmlm-patches/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		ezmlm-${EZMLM_VERSION}${EXTRACT_SUFX}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Improved version of the ezmlm mailing list manager

USE_QMAIL_RUN=	yes

CONFLICTS=	ezmlm-0.*

# LANGUAGE is the ISO code for the language to use in ezmlmrc
LANGUAGE?=	en_US

SUB_FILES=	pkg-message

OPTIONS=	MYSQL "Build MySQL extensions" off \
		PGSQL "Build PostgreSQL extensions" off

.include <bsd.port.pre.mk>

# If WITH_MYSQL is defined, build with MySQL extensions
.if defined(WITH_MYSQL)
USE_MYSQL=	yes
EXTRACT_INCLUDE+=	-I${LOCALBASE}/include/mysql
EXTRACT_LIB+=	-L${LOCALBASE}/lib/mysql -lmysqlclient -lm
.elif defined(WITH_PGSQL)
USE_PGSQL=	yes
EXTRACT_INCLUDE+=	-I${LOCALBASE}/include
EXTRACT_LIB+=	-L${LOCALBASE}/lib -lpq -lcrypt
.endif

ALL_TARGET=	it ${LANGUAGE}

WRKSRC=		${WRKDIR}/ezmlm-${EZMLM_VERSION}
EZMLM_VERSION=	0.53

PROGRAMS=	ezmlm-archive ezmlm-cgi ezmlm-clean ezmlm-cron ezmlm-gate \
		ezmlm-get ezmlm-idx ezmlm-issubn ezmlm-limit ezmlm-list \
		ezmlm-make ezmlm-manage ezmlm-moderate ezmlm-request \
		ezmlm-reject ezmlm-return ezmlm-send ezmlm-split ezmlm-store \
		ezmlm-sub ezmlm-tstdig ezmlm-unsub ezmlm-warn ezmlm-weed
SCRIPTS=	ezmlm-accept ezmlm-check ezmlm-glconf ezmlm-mktab ezmlm-test
CONFIG=		ezmlmglrc ezmlmrc ezmlmsubrc

MAN1=	ezmlm-accept.1 ezmlm-archive.1 ezmlm-cgi.1 ezmlm-check.1 \
	ezmlm-clean.1 ezmlm-cron.1 ezmlm-gate.1 ezmlm-get.1 \
	ezmlm-glconf.1 ezmlm-idx.1 ezmlm-issubn.1 ezmlm-limit.1 \
	ezmlm-list.1 ezmlm-make.1 ezmlm-manage.1 ezmlm-mktab.1 \
	ezmlm-moderate.1 ezmlm-reject.1 ezmlm-request.1 \
	ezmlm-return.1 ezmlm-send.1 ezmlm-split.1 ezmlm-store.1 \
	ezmlm-sub.1 ezmlm-test.1 ezmlm-tstdig.1 ezmlm-unsub.1 \
	ezmlm-warn.1 ezmlm-weed.1
MAN5=	ezmlm.5 ezmlmglrc.5 ezmlmrc.5 ezmlmsubrc.5
DOCS=	CHANGES.idx DOWNGRADE.idx FAQ.idx INSTALL.idx README.idx UPGRADE.idx

pre-patch:
	@${MV} -f ${WRKDIR}/ezmlm-idx-${PORTVERSION}/* ${WRKSRC}
	@cd ${WRKSRC} && ${PATCH} ${PATCH_ARGS} < idx.patch

post-patch:
	@${ECHO_CMD} /usr/sbin > ${WRKSRC}/conf-cron
	@${ECHO_CMD} ${PREFIX}/bin > ${WRKSRC}/conf-bin
	@${ECHO_CMD} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@${ECHO_CMD} ${CC} -s > ${WRKSRC}/conf-ld
.if defined(WITH_MYSQL)
	@${ECHO_CMD} mysql > ${WRKSRC}/conf-sub
	@${ECHO_CMD} ${EXTRACT_INCLUDE} > ${WRKSRC}/sub_mysql/conf-sqlcc
	@${ECHO_CMD} ${EXTRACT_LIB} > ${WRKSRC}/sub_mysql/conf-sqlld
.elif defined(WITH_PGSQL)
	@${ECHO_CMD} pgsql > ${WRKSRC}/conf-sub
	@${ECHO_CMD} ${EXTRACT_INCLUDE} > ${WRKSRC}/sub_pgsql/conf-sqlcc
	@${ECHO_CMD} ${EXTRACT_LIB} > ${WRKSRC}/sub_pgsql/conf-sqlld
.endif
	@${ECHO_CMD} ${PREFIX}/man > ${WRKSRC}/conf-man
	@${ECHO_CMD} ${QMAIL_PREFIX} > ${WRKSRC}/conf-qmail
	@${REINPLACE_CMD} -e 's,/etc/ezmlm/,${PREFIX}/etc/ezmlm/,' \
		${WRKSRC}/idx.h

do-install:
	@cd ${WRKSRC} && \
		${INSTALL_PROGRAM} ${PROGRAMS} ${PREFIX}/bin && \
		${INSTALL_SCRIPT} ${SCRIPTS} ${PREFIX}/bin && \
		${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1 && \
		${INSTALL_MAN} ${MAN5} ${MANPREFIX}/man/man5
	@${MKDIR} ${PREFIX}/etc/ezmlm
.for file in ${CONFIG}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/etc/ezmlm/${file}.sample
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
