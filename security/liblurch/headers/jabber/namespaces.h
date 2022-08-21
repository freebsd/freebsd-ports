/*
 * purple - Jabber Protocol Plugin
 *
 * Purple is the legal property of its developers, whose names are too numerous
 * to list here.  Please refer to the COPYRIGHT file distributed with this
 * source distribution.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111-1301  USA
 *
 */

#ifndef PURPLE_JABBER_NAMESPACES_H_
#define PURPLE_JABBER_NAMESPACES_H_

#define NS_XMPP_BIND "urn:ietf:params:xml:ns:xmpp-bind"
#define NS_XMPP_CLIENT "jabber:client"
#define NS_XMPP_SASL "urn:ietf:params:xml:ns:xmpp-sasl"
#define NS_XMPP_SESSION "urn:ietf:params:xml:ns:xmpp-session"
#define NS_XMPP_STANZAS "urn:ietf:params:xml:ns:xmpp-stanzas"
#define NS_XMPP_STREAMS "http://etherx.jabber.org/streams"
#define NS_XMPP_TLS "urn:ietf:params:xml:ns:xmpp-tls"

/* XEP-0012 Last Activity (and XEP-0256 Last Activity in Presence) */
#define NS_LAST_ACTIVITY "jabber:iq:last"

/* XEP-0030 Service Discovery */
#define NS_DISCO_INFO "http://jabber.org/protocol/disco#info"
#define NS_DISCO_ITEMS "http://jabber.org/protocol/disco#items"

/* XEP-0047 IBB (In-band bytestreams) */
#define NS_IBB "http://jabber.org/protocol/ibb"

/* XEP-0065 SOCKS5 Bytestreams */
#define NS_BYTESTREAMS "http://jabber.org/protocol/bytestreams"

/* XEP-0066 Out of Band Data (OOB) */
#define NS_OOB_IQ_DATA "jabber:iq:oob"
#define NS_OOB_X_DATA  "jabber:x:oob"

/* XEP-0071 XHTML-IM (rich-text messages) */
#define NS_XHTML_IM "http://jabber.org/protocol/xhtml-im"
#define NS_XHTML "http://www.w3.org/1999/xhtml"

/* XEP-0084 v0.12 User Avatar */
#define NS_AVATAR_0_12_DATA     "http://www.xmpp.org/extensions/xep-0084.html#ns-data"
#define NS_AVATAR_0_12_METADATA "http://www.xmpp.org/extensions/xep-0084.html#ns-metadata"

/* XEP-0084 v1.1 User Avatar */
#define NS_AVATAR_1_1_DATA      "urn:xmpp:avatar:data"
#define NS_AVATAR_1_1_METADATA  "urn:xmpp:avatar:metadata"

/* XEP-0096 SI File Transfer */
#define NS_SI_FILE_TRANSFER 	"http://jabber.org/protocol/si/profile/file-transfer"

/* XEP-0124 Bidirectional-streams Over Synchronous HTTP (BOSH) */
#define NS_BOSH "http://jabber.org/protocol/httpbind"

/* XEP-0191 Simple Communications Blocking */
#define NS_SIMPLE_BLOCKING "urn:xmpp:blocking"

/* XEP-0199 Ping */
#define NS_PING "urn:xmpp:ping"

/* XEP-0202 Entity Time */
#define NS_ENTITY_TIME "urn:xmpp:time"

/* XEP-0203 Delayed Delivery (and legacy delayed delivery) */
#define NS_DELAYED_DELIVERY "urn:xmpp:delay"
#define NS_DELAYED_DELIVERY_LEGACY "jabber:x:delay"

/* XEP-0206 XMPP over BOSH */
#define NS_XMPP_BOSH "urn:xmpp:xbosh"

/* XEP-0224 Attention */
#define NS_ATTENTION "urn:xmpp:attention:0"

/* XEP-0231 BoB (Bits of Binary) */
#define NS_BOB "urn:xmpp:bob"

/* XEP-0237 Roster Versioning */
#define NS_ROSTER_VERSIONING "urn:xmpp:features:rosterver"

/* XEP-0264 File Transfer Thumbnails (Thumbs) */
#define NS_THUMBS "urn:xmpp:thumbs:0"

/* Google extensions */
#define NS_GOOGLE_CAMERA "http://www.google.com/xmpp/protocol/camera/v1"
#define NS_GOOGLE_VIDEO "http://www.google.com/xmpp/protocol/video/v1"
#define NS_GOOGLE_VOICE "http://www.google.com/xmpp/protocol/voice/v1"
#define NS_GOOGLE_JINGLE_INFO "google:jingleinfo"

#define NS_GOOGLE_MAIL_NOTIFY "google:mail:notify"
#define NS_GOOGLE_ROSTER "google:roster"

#define NS_GOOGLE_PROTOCOL_SESSION "http://www.google.com/xmpp/protocol/session"
#define NS_GOOGLE_SESSION "http://www.google.com/session"
#define NS_GOOGLE_SESSION_PHONE "http://www.google.com/session/phone"
#define NS_GOOGLE_SESSION_VIDEO "http://www.google.com/session/video"

#endif /* PURPLE_JABBER_NAMESPACES_H_ */
