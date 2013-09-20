# Created by: Scott Blachowicz <scott+ports@sabami.seaslug.org>
# $FreeBSD$

PORTNAME=	nmh
PORTVERSION=	1.5
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	nmh

MAINTAINER=	cy@FreeBSD.org
COMMENT=	A cleaned up MH mailer suite

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/libexec/nmh \
		--sysconfdir=${PREFIX}/etc/nmh
.ifdef NMH_EDITOR
CONFIGURE_ARGS+=	--with-editor=${NMH_EDITOR}
.endif
.ifdef NMH_MASQUERADE
CONFIGURE_ARGS+=	--enable-masquerade="${NMH_MASQUERADE}"
.endif
.ifndef NMH_LOCKING
NMH_LOCKING=FLOCK_LOCKING
.endif
.ifdef NMH_MTS
CONFIGURE_ARGS+=	--with-mts=${NMH_MTS}
.endif
.ifdef NMH_PAGER
CONFIGURE_ARGS+=	--with-pager=${NMH_PAGER}
.endif
.ifdef NMH_POP
CONFIGURE_ARGS+=	--${NMH_POP}-pop
.else
CONFIGURE_ARGS+=	--enable-pop
.endif
.ifdef NMH_SMTPSERVERS
CONFIGURE_ARGS+=	--with-smtpservers="${NMH_SMTPSERVERS}"
.endif

.ifdef NMH_EXTRA_CONFIGURE_ARGS
CONFIGURE_ARGS+=	${NMH_EXTRA_CONFIGURE_ARGS}
.endif
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-D${NMH_LOCKING} -O

CONFIGURE_ARGS+=	--docdir=${DOCSDIR}

OPTIONS_DEFINE=	SASL2
SASL2_DESC=	Cyrus SASL2 support
NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSASL2}
LIB_DEPENDS+=		sasl2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--with-cyrus-sasl
CONFIGURE_ENV+=		LDFLAGS=-L"${PREFIX}"/lib CPPFLAGS=" -I${PREFIX}/include"
.endif

MAN1=	ali.1 anno.1 burst.1 comp.1 dist.1 flist.1 flists.1 fnext.1 \
	folder.1 folders.1 forw.1 fprev.1 inc.1 install-mh.1 mark.1 \
	mh-chart.1 mhbuild.1 mhl.1 mhlist.1 mhmail.1 mhn.1 \
	mhparam.1 mhpath.1 mhshow.1 mhstore.1 msgchk.1 msh.1 \
	next.1 new.1 nmh.1 packf.1 pick.1 prev.1 prompter.1 rcvdist.1 \
	rcvpack.1 rcvstore.1 rcvtty.1 refile.1 repl.1 rmf.1 rmm.1 \
	scan.1 send.1 sendfiles.1 show.1 slocal.1 \
	sortm.1 unseen.1 whatnow.1 whom.1

MAN5=	mh-alias.5 mh-draft.5 mh-format.5 mh-mail.5 mh-profile.5 \
	mh-sequence.5 mh-tailor.5 mts.conf.5

MLINKS=	mh-profile.5 mh_profile.5

MAN8=	ap.8 conflict.8 dp.8 fmtdump.8 post.8
CONFLICTS=	ja-mh-[0-9]*

post-patch:
	@${REINPLACE_CMD} -e "s|autoconf|${AUTOCONF}|;\
		s|autoheader|${AUTOHEADER}|" ${WRKSRC}/Makefile.in

post-install:
	@PKG_PREFIX='${PREFIX}' ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
