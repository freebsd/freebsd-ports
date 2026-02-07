import asyncio
from playwright.async_api import async_playwright

async def main():
    async with async_playwright() as p:
        #for browser_type in [p.chromium, p.firefox, p.webkit]:
        for browser_type in [p.firefox]:
            browser = await browser_type.launch()
            page = await browser.new_page()
            await page.goto('http://playwright.dev')
            await page.screenshot(path=f'example-{browser_type.name}-async.png')
            await browser.close()

asyncio.run(main())
