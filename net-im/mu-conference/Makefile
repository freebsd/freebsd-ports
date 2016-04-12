# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	mu-conference
PORTVERSION=	0.8
PORTREVISION=	6
CATEGORIES=	net-im
MASTER_SITES=	http://download.gna.org/mu-conference/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Multi-User Conferencing component for Jabber

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libidn.so:dns/libidn

USES=		pkgconfig shebangfix
SHEBANG_FILES=	scripts/roommaker.pl scripts/roomname.pl
USE_GNOME=	glib20
USE_RC_SUBR=	${PORTNAME}

OPTIONS_DEFINE=	MYSQL DOCS
OPTIONS_DEFAULT=DAEMON
OPTIONS_SINGLE=	SERVER
OPTIONS_SINGLE_SERVER=	JABBER JABBERD EJABBERD DAEMON

JABBER_DESC=	Use with jabberd14 (net-im/jabber)
JABBERD_DESC=	Use with jabberd 2.x (net-im/jabberd)
EJABBERD_DESC=	Use with ejabberd (net-im/ejabberd)
DAEMON_DESC=	Use builtin daemon

SUB_FILES+=	pkg-message README.FreeBSD.jabberd14 \
		README.FreeBSD.jabberd2 README.FreeBSD.external

DOCFILES=	AUTHORS ChangeLog FAQ LICENSE README TODO \
		XEP0045_SUPPORT muc-default.xml style.css

PORTDOCS=	*

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CFLAGS+=	-DHAVE_MYSQL
LIBS+=		`${LOCALBASE}/bin/mysql_config --libs`
DOCFILES+=	README.sql mu-conference.sql
.endif

MUC_LOGDIR?=	/var/log/mu-conference

.if ${PORT_OPTIONS:MJABBER}
JABBER_REQUIRE?=        jabber
JABBER_USER?=           jabber
JABBER_PIDDIR?=         /var/run/jabberd
JABBER_SPOOLDIR?=       /var/spool/jabberd
RUN_DEPENDS+=           jabberd14:net-im/jabber
.elif ${PORT_OPTIONS:MJABBERD}
JABBER_REQUIRE?=        jabberd
JABBER_USER?=           jabber
JABBER_PIDDIR?=         /var/jabberd/pid
JABBER_SPOOLDIR?=       /var/spool/jabber
RUN_DEPENDS+=           jabberd:net-im/jabberd
.elif ${PORT_OPTIONS:MEJABBERD}
JABBER_REQUIRE?=        ejabberd
JABBER_USER?=           ejabberd
JABBER_PIDDIR?=         /var/jabberd/pid
JABBER_SPOOLDIR?=       /var/spool/jabber
RUN_DEPENDS+=           ejabberdctl:net-im/ejabberd
.elif ${PORT_OPTIONS:MDAEMON}
JABBER_REQUIRE?=        DAEMON
JABBER_USER?=           nobody
JABBER_PIDDIR?=         /var/run/mu-conference
JABBER_SPOOLDIR?=       /var/spool/mu-conference
.endif

SUB_LIST+=	JABBER_REQUIRE="${JABBER_REQUIRE}" \
		JABBER_PIDDIR="${JABBER_PIDDIR}" \
		JABBER_SPOOLDIR="${JABBER_SPOOLDIR}" \
		JABBER_USER=${JABBER_USER} \
		MUC_LOGDIR=${MUC_LOGDIR}

post-patch:
	@${REINPLACE_CMD} -e 's/=$$(CFLAGS)/=/g;s/^CFLAGS[:]*=/CFLAGS+=/g' \
		-e 's/^CC:*=/CC?=/g;s|gcc |$$(CC) |;s|-O2||g' \
		-e 's#`pkg-config#-I${LOCALBASE}/include `${LOCALBASE}/bin/pkg-config#g' \
		${WRKSRC}/Makefile ${WRKSRC}/*/Makefile \
		${WRKSRC}/*/*/Makefile
	@${REINPLACE_CMD} -e 's#<spool>\./spool/chat.localhost#<spool>${JABBER_SPOOLDIR}/conference.localhost#g' \
		-e 's#<logdir>\./syslogs#<logdir>${LOGDIR}#g' \
		-e 's#<logdir>\./logs#<logdir>${JABBER_SPOOLDIR}/conference.localhost/logs#g' \
		-e 's#<pidfile>\.#<pidfile>${JABBER_PIDDIR}#g' \
		${WRKSRC}/muc-default.xml

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mu-conference ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/muc-default.xml ${STAGEDIR}${PREFIX}/etc/muc.xml.sample
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/scripts
.for FILE in README.FreeBSD.jabberd14 README.FreeBSD.jabberd2 README.FreeBSD.external
	@${INSTALL_DATA} ${WRKDIR}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
.for FILE in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/scripts/README ${STAGEDIR}${DOCSDIR}/scripts
.for FILE in roommaker.pl roomname.pl
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/${FILE} ${STAGEDIR}${DOCSDIR}/scripts
.endfor
.endif

.include <bsd.port.mk>
