# Created by: Michiel van Baak <michiel@vanbaak.eu
# $FreeBSD$

PORTNAME=	hockeypuck
DISTVERSION=	g20180725
CATEGORIES=	security

MAINTAINER=	michiel@vanbaak.eu
COMMENT=	Synchronizing Key Server, a fast OpenPGP keyserver

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

GO_PKGNAME=	github.com/hockeypuck/server
GO_BUILDFLAGS=	-ldflags "-X github.com/hockeypuck/server.version=${PORTVERSION}"
GO_TARGET=	github.com/hockeypuck/server/cmd/hockeypuck \
		github.com/hockeypuck/server/cmd/hockeypuck-dump \
		github.com/hockeypuck/server/cmd/hockeypuck-load \
		github.com/hockeypuck/server/cmd/hockeypuck-pbuild

USE_GITHUB=	yes

GH_PROJECT=	server
GH_TAGNAME=	16d0faf
GH_TUPLE=	golang:crypto:24ffb5feb3312a39054178a4b0a4554fc2201248:gocrypto/vendor/golang.org/x/crypto \
		BurntSushi:toml:056c9bc7be7190eaa7715723883caffa5f8fa3e4:toml/vendor/github.com/BurntSushi/toml \
		carbocation:interpose:50c09d12f8624ab10532f931cb630d0bf5f7c2c7:interpose/vendor/github.com/carbocation/interpose \
		julienschmidt:httprouter:8c199fb6259ffc1af525cc3ad52ee60ba8359669:httprouter/vendor/github.com/julienschmidt/httprouter \
		lib:pq:93e9980741c9e593411b94e07d5bad8cfb4809db:pq/vendor/github.com/lib/pq \
		syndtr:goleveldb:012f65f74744ed62a80abac6e9a8c86e71c2b6fa:goleveldb/vendor/github.com/syndtr/goleveldb \
		syndtr:gosnappy:156a073208e131d7d2e212cb749feae7c339e846:gosnappy/vendor/github.com/syndtr/gosnappy \
		go-basen:basen:c8826fd23a9b8fee76fd0c3c5ac34a44cc15dc75:basen/vendor/gopkg.in/basen.v1 \
		go-errgo:errgo:81357a83344ddd9f7772884874e5622c2a3da21c:errgo/vendor/gopkg.in/errgo.v1 \
		go-mgo:mgo:c6a7dce14133ccac2dcac3793f1d6e2ef048503a:mgo/vendor/gopkg.in/mgo.v2 \
		go-tomb:tomb:14b3d72120e8d10ea6e6b7f87f7175734b1faab8:tomb/vendor/gopkg.in/tomb.v2 \
		hockeypuck:conflux:aa90c9a973df4ce6f26a9a8eda5418d35ef647d2:conflux/vendor/gopkg.in/hockeypuck/conflux.v2 \
		hockeypuck:hkp:148cf10d066b925e0331ba77e5b86c65865ba1eb:hkp/vendor/gopkg.in/hockeypuck/hkp.v1 \
		hockeypuck:logrus:55eb11d21d2a31a3cc93838241d04800f52e823d:logrus/vendor/gopkg.in/hockeypuck/logrus.v0 \
		hockeypuck:mgohkp:315bc3b0e2bb701822b0445b1ebb02ee9a2c0aa9:mgohk/vendor/gopkg.in/hockeypuck/mgohkp.v1 \
		hockeypuck:openpgp:24bbf23d26ff51ca7a8e051998a8da67b6043689:openpgp/vendor/gopkg.in/hockeypuck/openpgp.v1 \
		hockeypuck:pghkp:098cd7e4f3ec817e44b90dcc2833a84f736f6042:pghkp/vendor/gopkg.in/hockeypuck/pghkp.v1 \

USE_RC_SUBR=	hockeypuck

USERS=		_hockeypuck
GROUPS=		_hockeypuck

.include <bsd.port.mk>
