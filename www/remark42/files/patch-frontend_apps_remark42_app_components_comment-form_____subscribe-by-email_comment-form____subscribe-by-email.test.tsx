--- frontend/apps/remark42/app/components/comment-form/__subscribe-by-email/comment-form__subscribe-by-email.test.tsx.orig	2024-05-10 03:32:00 UTC
+++ frontend/apps/remark42/app/components/comment-form/__subscribe-by-email/comment-form__subscribe-by-email.test.tsx
@@ -193,7 +193,7 @@ describe('<SubscribeByEmailForm/>', () => {
 
   it('should send form by paste valid token', async () => {
     const wrapper = createWrapper();
-    const onInputEmail = wrapper.find(Input).prop('onInput');
+    const onInputEmail = wrapper.find(Input).prop('onInput') as Function;
     const form = wrapper.find('form');
 
     expect(typeof onInputEmail === 'function').toBe(true);
@@ -220,7 +220,7 @@ describe('<SubscribeByEmailForm/>', () => {
   it('should pass throw unsubscribe process', async () => {
     const store = mockStore({ ...initialStore, user: { email_subscription: true } });
     const wrapper = createWrapper(store);
-    const onClick = wrapper.find(Button).prop('onClick');
+    const onClick = wrapper.find(Button).prop('onClick') as Function;
 
     expect(typeof onClick === 'function').toBe(true);
 
